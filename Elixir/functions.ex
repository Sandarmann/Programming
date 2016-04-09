#So we have strings " string "
#We have everything like in pythong [] lists, {} tuples
#Handles some pretty cool arithmetic

#Here is an anonymous function

add = fn a, b -> a + b end

#With the sublimelinter it will let us know when things are not used or useless so this will thtow a warning just for your information
is_function(add)


IO.puts "hello"

IO.puts add.(1,2)


#Linked lists
a = [1, 2, true, 3]
IO.puts length a

#Concatinate linkes lists
a = [1, 2, 3, 4]
b = [1, 3, 4, 5]

IO.puts length a++b #returns 8

#Subtract lists

IO.puts length a -- b #returns only 1

#get head of list

IO.puts hd a

#get tail
IO.puts tl a

#Interesting enough if you print a linked list it will interpret the numebrs as ascii characters for the most part
IO.puts [104, 101, 108, 108, 111] #prints hello

#tuples

tuple = {:ok, "sup"}
IO.puts elem(tuple, 1)

#String concatination is done with <>

#or and and are short-circuit operators. They only execute the right side if the left side is not enough to determine the result:

#Besides these boolean operators, Elixir also provides ||, && and ! which accept arguments of any type. For these operators, all values except false and nil will evaluate to true:


#SOME INTERESTING things

IO.puts 1 == 1.0

IO.puts 1 === 1.0

#The reason we can compare different data types is pragmatism. Sorting algorithms don't need to worry about different data types in order to sort. The overall sorting order is defined below:

#number < atom < reference < functions < port < pid < tuple < maps < list < bitstring
