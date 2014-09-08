#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* define IDs for controls */

#define IDE_SURNAME1 100
#define IDE_PHONE1 101
#define IDE_NAME2 102
#define IDE_SURNAME2 103
#define IDE_PHONE2 104

#define IDL_PEOPLE 200

#define IDB_ADD 300
#define IDB_ERASES 301
#define IDB_ERASEA 302
#define IDB_SAVE 303


#define MAX 500   /* max number of records */
#define ENTRY 31    /* max number of chars for name, surname and phone */

#define ONE 49    /* define ASCII values for numbers 1-8 */
#define TWO 50
#define THREE 51
#define FOUR 52
#define FIVE 53
#define SIX 54
#define SEVEN 55
#define EIGHT 56    

#define FSIZE 46500    /* the size of the database file in bytes */

/* prototypes */
LRESULT CALLBACK WinProc(HWND, UINT, WPARAM, LPARAM);
void save();
void defragArray();
int findFreeTemp();
int findFreePeople();
void fillList();
void checkHandle( HWND );

char szClassName[] = "WinApp";
int selItem = LB_ERR;

HWND hwndMain;

/* handles for buttons */
HWND hwndAdd;    
HWND hwndErasesel;
HWND hwndEraseall;
HWND hwndSave;

/* handle for list */
HWND hwndList;

/* handle for other controls */
HWND hwndCtls;

/* handle for default font */
HFONT font; 

MSG msg;
WNDCLASSEX wincls;

struct data 
{
       char name[ENTRY];
       char surname[ENTRY];
       char phone[ENTRY];
};

struct data People[MAX];
struct data temp[MAX];

int WINAPI WinMain (HINSTANCE hInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nFunsterStil)

{
    FILE *fp;
    int fileSize;
    int i;
            
    if ( (fp=fopen("phonebook.dat" , "r")) == NULL)
    {
         
         if( (fp=fopen("phonebook.dat" , "w")) == NULL ) 
         {
             MessageBox( hwndMain, "Error", "Error accessing the file!", MB_OK | MB_ICONEXCLAMATION );
             return;
         }
         
         
         save(); 
         
         
    } 
    
    fp=fopen("phonebook.dat" , "r");
        
    fseek (fp , 0 , SEEK_END);
    fileSize = ftell (fp);    /* calculate the size of the file in bytes */
    rewind( fp );
    
    if( fileSize != FSIZE )    /* check if the file isn't corrupted by checking its size */
    {
        MessageBox( hwndMain, "The file is corrupted!", "Error", MB_OK | MB_ICONEXCLAMATION );    /* if it's wrong, exit */
        fclose(fp);
        return;
    } 
    
    
    fread(People , sizeof People , 1 , fp);
   
    if (ferror(fp))
    {
            MessageBox( hwndMain, "Error accessing the file!", "Error", MB_OK | MB_ICONEXCLAMATION );
            fclose(fp);
            return;
    } 
    
    defragArray();
    save();
    
    wincls.cbSize = sizeof( WNDCLASSEX );
    wincls.style = CS_DBLCLKS;
    wincls.lpfnWndProc = WinProc;
    wincls.cbClsExtra = 0;
    wincls.cbWndExtra = 0;
    wincls.hInstance = hInstance;
    wincls.lpszClassName = szClassName;
    wincls.hIcon = LoadIcon( NULL, IDI_APPLICATION );
    wincls.hIconSm = LoadIcon( NULL, IDI_APPLICATION );
    wincls.hCursor = LoadCursor( NULL, IDC_ARROW );
    wincls.lpszMenuName = NULL;
    wincls.hbrBackground = (HBRUSH) ( COLOR_BTNFACE + 1 );

    if( !RegisterClassEx( &wincls ) )
    {
        MessageBox( hwndMain, "Can't register window class!", "Error", MB_OK | MB_ICONEXCLAMATION );
        return 0;
    }
    
    hwndMain = CreateWindowEx (
           0,
           szClassName,
           "Phonebook 1.1",
           WS_MINIMIZEBOX | WS_VISIBLE | WS_SYSMENU,
           CW_USEDEFAULT,
           CW_USEDEFAULT,
           655,
           450,
           HWND_DESKTOP,
           NULL,
           hInstance,
           NULL
    );
    checkHandle( hwndMain );
   
    UpdateWindow( hwndMain );

    while( GetMessage( &msg, NULL, 0, 0 ) )
    {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
    }

    return msg.wParam;
}

LRESULT CALLBACK WinProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
    switch( msg )
    {
        case WM_CREATE:
             {
             /* create the font */
             HDC hdc;
             int fheight = 10;
             long lfHeight;
             
             hdc = GetDC(NULL);
             lfHeight = -MulDiv(fheight, GetDeviceCaps(hdc, LOGPIXELSY), 72);
             ReleaseDC(NULL, hdc);
             
             font = CreateFont( lfHeight, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Arial" );
                          
             /* create the list control */
             hwndList = CreateWindowEx (
                      WS_EX_CLIENTEDGE,
                      "listbox",
                      NULL,
                      WS_CHILD | WS_VISIBLE | LBS_NOTIFY | WS_VSCROLL,
                      12,
                      60,
                      166,
                      351,
                      hwnd,
                      (HMENU) IDL_PEOPLE,
                      GetModuleHandle( NULL ),
                      NULL
             );
             checkHandle( hwndList );
             SendMessage( hwndList, WM_SETFONT, font, MAKELPARAM(FALSE, 0) );
             fillList();
                          
             /* ctreate statics */
             hwndCtls = CreateWindowEx (
                      WS_EX_CLIENTEDGE,
                      "static",
                      "Names",
                      WS_CHILD | WS_VISIBLE,
                      12,
                      15,
                      166,
                      19,
                      hwnd,
                      NULL,
                      GetModuleHandle( NULL ),
                      NULL
             );
             checkHandle( hwndCtls );
             SendMessage( hwndCtls, WM_SETFONT, font, MAKELPARAM(FALSE, 0) );
             
             hwndCtls = CreateWindowEx (
                      WS_EX_CLIENTEDGE,
                      "static",
                      "Surname",
                      WS_CHILD | WS_VISIBLE,
                      240,
                      15,
                      166,
                      19,
                      hwnd,
                      NULL,
                      GetModuleHandle( NULL ),
                      NULL
             );
             checkHandle( hwndCtls );
             SendMessage( hwndCtls, WM_SETFONT, font, MAKELPARAM(FALSE, 0) );
             
             hwndCtls = CreateWindowEx (
                      WS_EX_CLIENTEDGE,
                      "static",
                      "Phone",
                      WS_CHILD | WS_VISIBLE,
                      465,
                      15,
                      166,
                      19,
                      hwnd,
                      NULL,
                      GetModuleHandle( NULL ),
                      NULL
             );
             checkHandle( hwndCtls );
             SendMessage( hwndCtls, WM_SETFONT, font, MAKELPARAM(FALSE, 0) );
             
             hwndCtls = CreateWindowEx (
                      WS_EX_CLIENTEDGE,
                      "static",
                      "Name",
                      WS_CHILD | WS_VISIBLE,
                      240,
                      168,
                      85,
                      19,
                      hwnd,
                      NULL,
                      GetModuleHandle( NULL ),
                      NULL
             );
             checkHandle( hwndCtls );
             SendMessage( hwndCtls, WM_SETFONT, font, MAKELPARAM(FALSE, 0) );
             
             hwndCtls = CreateWindowEx (
                      WS_EX_CLIENTEDGE,
                      "static",
                      "Surname",
                      WS_CHILD | WS_VISIBLE,
                      240,
                      210,
                      85,
                      19,
                      hwnd,
                      NULL,
                      GetModuleHandle( NULL ),
                      NULL
             );
             checkHandle( hwndCtls );
             SendMessage( hwndCtls, WM_SETFONT, font, MAKELPARAM(FALSE, 0) );
             
             hwndCtls = CreateWindowEx (
                      WS_EX_CLIENTEDGE,
                      "static",
                      "Phone",
                      WS_CHILD | WS_VISIBLE,
                      240,
                      249,
                      85,
                      19,
                      hwnd,
                      NULL,
                      GetModuleHandle( NULL ),
                      NULL
             );
             checkHandle( hwndCtls );
             SendMessage( hwndCtls, WM_SETFONT, font, MAKELPARAM(FALSE, 0) );
             
             /* create edits */
             hwndCtls = CreateWindowEx (
                      WS_EX_CLIENTEDGE,
                      "edit",
                      NULL,
                      WS_CHILD | WS_VISIBLE | ES_READONLY | ES_AUTOHSCROLL,
                      240,
                      60,
                      166,
                      19,
                      hwnd,
                      (HMENU) IDE_SURNAME1,
                      GetModuleHandle( NULL ),
                      NULL
             );
             checkHandle( hwndCtls );
             SendMessage( hwndCtls, WM_SETFONT, font, MAKELPARAM(FALSE, 0) );
             
             hwndCtls = CreateWindowEx (
                      WS_EX_CLIENTEDGE,
                      "edit",
                      NULL,
                      WS_CHILD | WS_VISIBLE | ES_READONLY | ES_AUTOHSCROLL,
                      465,
                      60,
                      166,
                      19,
                      hwnd,
                      (HMENU) IDE_PHONE1,
                      GetModuleHandle( NULL ),
                      NULL
             );
             checkHandle( hwndCtls );
             SendMessage( hwndCtls, WM_SETFONT, font, MAKELPARAM(FALSE, 0) );
             
             hwndCtls = CreateWindowEx (
                      WS_EX_CLIENTEDGE,
                      "edit",
                      NULL,
                      WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL,
                      375,
                      168,
                      166,
                      19,
                      hwnd,
                      (HMENU) IDE_NAME2,
                      GetModuleHandle( NULL ),
                      NULL
             );
             checkHandle( hwndCtls );
             SendMessage( hwndCtls, WM_SETFONT, font, MAKELPARAM(FALSE, 0) );
             
             hwndCtls = CreateWindowEx (
                      WS_EX_CLIENTEDGE,
                      "edit",
                      NULL,
                      WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL,
                      375,
                      210,
                      166,
                      19,
                      hwnd,
                      (HMENU) IDE_SURNAME2,
                      GetModuleHandle( NULL ),
                      NULL
             );
             checkHandle( hwndCtls );
             SendMessage( hwndCtls, WM_SETFONT, font, MAKELPARAM(FALSE, 0) );
             
             hwndCtls = CreateWindowEx (
                      WS_EX_CLIENTEDGE,
                      "edit",
                      NULL,
                      WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL | ES_NUMBER,
                      375,
                      249,
                      166,
                      19,
                      hwnd,
                      (HMENU) IDE_PHONE2,
                      GetModuleHandle( NULL ),
                      NULL
             );
             checkHandle( hwndCtls );
             SendMessage( hwndCtls, WM_SETFONT, font, MAKELPARAM(FALSE, 0) );
             
             /* create buttons */
             hwndAdd = CreateWindowEx (
                      0,
                      "button",
                      "Add",
                      WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                      591,
                      168,
                      43,
                      100,
                      hwnd,
                      (HMENU) IDB_ADD,
                      GetModuleHandle( NULL ),
                      NULL
             );
             checkHandle( hwndAdd );
             SendMessage( hwndAdd, WM_SETFONT, font, MAKELPARAM(FALSE, 0) );
             
             hwndErasesel = CreateWindowEx (
                      0,
                      "button",
                      "Erase selected",
                      WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                      237,
                      359,
                      112,
                      40,
                      hwnd,
                      (HMENU) IDB_ERASES,
                      GetModuleHandle( NULL ),
                      NULL
             );
             checkHandle( hwndErasesel );
             SendMessage( hwndErasesel, WM_SETFONT, font, MAKELPARAM(FALSE, 0) );
             
             hwndEraseall = CreateWindowEx (
                      0,
                      "button",
                      "Erase all",
                      WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                      379,
                      359,
                      112,
                      40,
                      hwnd,
                      (HMENU) IDB_ERASEA,
                      GetModuleHandle( NULL ),
                      NULL
             );
             checkHandle( hwndEraseall );
             SendMessage( hwndEraseall, WM_SETFONT, font, MAKELPARAM(FALSE, 0) );
             
             hwndSave = CreateWindowEx (
                      0,
                      "button",
                      "Save",
                      WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                      522,
                      359,
                      112,
                      40,
                      hwnd,
                      (HMENU) IDB_SAVE,
                      GetModuleHandle( NULL ),
                      NULL
             );
             checkHandle( hwndSave );
             SendMessage( hwndSave, WM_SETFONT, font, MAKELPARAM(FALSE, 0) );
             break;
             }
        case WM_COMMAND:
             if( HIWORD( wParam ) == LBN_SELCHANGE && LOWORD( wParam ) == IDL_PEOPLE )
             {
                 selItem = SendMessage( hwndList, LB_GETCURSEL, 0, 0 );
                 
                 SetDlgItemText( hwndMain, IDE_SURNAME1, People[selItem].surname );
                 SetDlgItemText( hwndMain, IDE_PHONE1, People[selItem].phone );
             }
             
             if( HIWORD( wParam ) == BN_CLICKED )
             {
                 
                 switch( LOWORD( wParam ) )
                 {
                         case IDB_ERASES:
                              if( selItem == LB_ERR || findFreePeople() == 0 )
                              {
                                  MessageBox( hwndMain, "Please select first the item you want to delete!", "Error", MB_OK | MB_ICONEXCLAMATION );
                                  return;
                              }
                              People[selItem].name[0] = '\0';
                              SendMessage( hwndList, LB_DELETESTRING, selItem, 0 );
                              defragArray();
                              SetDlgItemText( hwndMain, IDE_SURNAME1, NULL );
                              SetDlgItemText( hwndMain, IDE_PHONE1, NULL );
                              selItem = LB_ERR;
                              break;
                         
                         case IDB_ERASEA:
                              ZeroMemory( People, sizeof People );
                              SendMessage( hwndList, LB_RESETCONTENT, 0, 0 );
                              SetDlgItemText( hwndMain, IDE_SURNAME1, NULL );
                              SetDlgItemText( hwndMain, IDE_PHONE1, NULL );
                              break;
                         
                         case IDB_SAVE:
                              save();
                              break;
                         
                         case IDB_ADD:
                              {
                              int pplFree;
                              pplFree = findFreePeople();
                                                                                         
                              if( GetWindowTextLength(GetDlgItem(hwnd, IDE_NAME2)) == 0 ||
                                  GetWindowTextLength(GetDlgItem(hwnd, IDE_SURNAME2)) == 0 ||
                                  GetWindowTextLength(GetDlgItem(hwnd, IDE_PHONE2)) == 0)
                              {
                                  MessageBox( hwndMain, "Please fill all the fields!", "Error", MB_OK | MB_ICONEXCLAMATION );
                                  return;
                              }
                              
                              GetDlgItemText( hwndMain, IDE_NAME2, People[pplFree].name, ENTRY - 1 );
                              GetDlgItemText( hwndMain, IDE_SURNAME2, People[pplFree].surname, ENTRY - 1 );
                              GetDlgItemText( hwndMain, IDE_PHONE2, People[pplFree].phone, ENTRY - 1 );
                              
                              SendMessage( hwndList, LB_ADDSTRING, 0, People[pplFree].name );
                              break;
                              }
                 }
             }
             break;
             
        case WM_DESTROY:
            PostQuitMessage( 0 );
            break;
        
        default:                      
            return DefWindowProc( hwnd, msg, wParam, lParam );
    }

    return 0;
       
} 

void save()     /* save the file */
{
    FILE *fp;

    if ( (fp=fopen("phonebook.dat" , "w")) == NULL)
    {     /* handle file errors */
      MessageBox( NULL, "Error", "Error accessing the file!", MB_OK | MB_ICONEXCLAMATION );
      return;
    } 
    
    fwrite(People , sizeof People , 1 , fp);    /* main instruction that writes the array */
    
    if (ferror(fp))     /* check for file errors */
    {
         MessageBox( NULL, "Error", "Error accessing the file!", MB_OK | MB_ICONEXCLAMATION );
         fclose(fp);
         return;
    } 
    
    fclose(fp);
} 

void defragArray()     /* defragments People for speed and easier handling */
{
     int i;
     int tmpFree;
          
     ZeroMemory( temp, sizeof temp );
     
     for( i=0; i<MAX; i++ )     /* copy all filled records to temp */
     {
          if( People[i].name[0] != '\0' )
          {
              tmpFree = findFreeTemp();
                              
              strcpy ( temp[tmpFree].name, People[i].name );
              strcpy( temp[tmpFree].surname, People[i].surname );
              strcpy( temp[tmpFree].phone, People[i].phone );
              
          }
     }
          
     ZeroMemory( People, sizeof People );
     
     for( i=0; i<MAX; i++ )     /* copy temp to People */
     {
          strcpy( People[i].name, temp[i].name );
          strcpy( People[i].surname, temp[i].surname );
          strcpy( People[i].phone, temp[i].phone );
     }
        
}

int findFreeTemp()     /* find free index of the temp and return it */
{
    int i;
    for(i=0; i<MAX; i++) 
    {
         if( temp[i].name[0] == '\0' )
         {
             return i;
             break;
         } 
                    
    } 
} 

int findFreePeople()     /* find free index of the People and return it */
{
    int i;
    for(i=0; i<MAX; i++) 
    {
         if( People[i].name[0] == '\0' )
         {
             return i;
             break;
         } 
                    
    } 
    return -1;     /* if list is full return -1 */
} 

void fillList()
{
     int i;
          
     SendMessage( hwndList, LB_RESETCONTENT, 0, 0 );
     
     for( i=0; i<findFreePeople(); i++ )
     {
          SendMessage( hwndList, LB_ADDSTRING, 0, People[i].name );
     }
}

void checkHandle( HWND handle )
{
    if( handle == NULL )
    {
        MessageBox( NULL, "Error", "Error creating window or control!", MB_OK | MB_ICONEXCLAMATION );
        return;
    }
}