========================================================================
    Fundamentals Of Programming - Assesment: "Database program".
	Created by Piotr Pawluk.
========================================================================

/////////////////////////////////////////////////////////////////////////////

The program specification :

   1. In the program code you should define the class Person or Car  or Building  with three different fields of any data type (all public), 2 constructors (one default and one with parameters), destructor.
   2. Program should ask the user for the name of the file to open.
   3. Program should open the file with name provided by the user in read mode and in a loop till the file end program should read line by line the values of the subsequent values of the class Person fields, create the subsequent objects of the class Person and using constructor or in any other way the program should assign the values obtained from the file to the fields of the created object.
      The example file content:
      Jaime Fernandez Molina
      Javier Madueno Entrenas
      Alberto Fernández Calvo
      The example of the first Person object fields values after the first file line reading operation:
      FirstName<= Jaime
      SecondName<=Fernandez
      ThirdName<=Molina
   4. Program should add every created object to the dynamic table or list (#include<list>)
      or vector structure (#include<vector>).
   5. After reading all file lines program should print on a screen the values of all objects fields for all created objects using table, vector or list iteration.
   6. After that the program should ask the user whether to change the values of the any created object fields, add the new object to the table or list or vector or delete the specified object. If the user asks the program to perform the change, addition or removal operation the program should do so.
   7. The final operation is to ask the user the name of the output file. The program should open that file in write mode and write all created objects fields values to this file one line per object.
8. All operations related to the user input and the file operations should be enclosed in the try catch blocks in order to handle the exceptions.

/////////////////////////////////////////////////////////////////////////////
