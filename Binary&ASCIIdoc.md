Incase you don't know anything about binary or the ascii table this might help you.

Our computers only speak the language binary (machine code). Thats why there are compilers for each programming language.
The compilers turn the code (example: python) into binary code, so the computer can process it. Binary is made out of 0's and 1's,
and to find them, we use the ASCII table.

In the ASCII table there are 128 characters that range from 0 to 127. You can't see the characters from 0 to 33, because they include stuff like 'NULL' or space or tab etc.
To see the ASCII table you can either search it up or print them in code. Here is a C++ example of printing all the characters in the ASCII table:

for (int i = 0; i < 127; i++)
{
  std::cout << i << " : " << (unsigned char)i << std::endl;
}

The above code will print out every single character in the ASCII table with their index.

If you have looked at the ASCII table, you might have seen A in 65 or a in 97. Well, what does this have to do with binary you may ask, but each binary chunk
represents a number. To find that number we can use 2 examples on turning these ASCII table character indexes into actual binary code.
EXAMPLE 1:
We get the number, lets use 65 for 'A', and we use the powers of 2.
The biggest number that is smaller or equal to 65 in the powers of 2 is 64 (2^6), then we extract 65 by 64, which is 1.
We use the same teqnique for 1, and it is 1 (2^0) itself. Now, we can't do anything with 0, so now we find the binary value!
We get all the numbers that are in the power of 2 table below and equal to 64, and put them in order, from big to small, which is:
1, 2, 4, 8, 16, 32, 64. We get the used numbers and turn them into 1's, get the un used numbers and turn them into 0. And now, you can see this: 01000001 = 65 = A!

EXAMPLE 2:
We get the number, lets use 65 for 'A' again, and divide them by 2. We then round the decimal value to the lowest integer and use it again. If it is an integer and
not a decimal value, we keep using it. For every decimal value, we will use 1, for integers, 0. An example of it:

65 / 2 = 32.5 -> 1 (its a decimal value)
32 / 2 = 16   -> 0 (its an integer value)
16 / 2 = 8    -> 0 (its an integer value)
8 / 2 = 4     -> 0 (its an integer value)
4 / 2 = 2     -> 0 (its an integer value)
2 / 2 = 1     -> 0 (its an integer value)
1 / 2 = 0.5   -> 1 (its a decimal value)

When we round 0.5 to the lowest integer, its 0, and then again we can't do anything with it. After this, we get the numbers "01000001" in binary. In this teqnique
though, we have to reverse the binary value. Yes, 01000001 reversed is 01000001 but, in other values, lets say a = 97 = 01100001, when we use this teqnique, it
comes out to be 1000011. So we should always reverse the binary value while using this teqnique.

In binary, computers pad raw binary values into 8-bit bytes, so thats why I put 0's at the end of the binary examples, and thats why 1 in binary is 00000001
instead of 1.

Now, decrypting the binary value is even easier. In binary, 0 is false or off and 1 is true or on. Each binary value is 2^index, and in coding, the index always
starts from 0, so note that. At every index, there is either a 0 or a 1 being used. In decrypting binary values, there is an addition process. The 0's and 1's
determine if their index is going to be used in the addition process. Example of getting the indexes for the process (A is going to be used):

1 : with index 0.
0 : with index 1.
0 : with index 2.
0 : with index 3.
0 : with index 4.
0 : with index 5.
1 : with index 6.

As you can see at the above example, only the indexes 0 and 6 have 1 (true) as their decider. The 1's say yes and the 0's say no. So we get the index 0 and 6
and do this equasion:

2^chosen index + 2^chosen index + 2^chosen index - this goes on according to how many indexes we have gotten.

2^0 + 2^6 = 65. 65! It matches with A!

The end of the document is here. Thank you for reading this :)!
