class Greeter
def initialize(name = "World")
@name  = name
end
def say_hi
puts "Hello #{name}"
end
def say_bye
puts "Bye #{name}"
end
end