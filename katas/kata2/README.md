
# 420. Strong Password Checker

A password is considered strong if below conditions are all met:

  1.   It has at least 6 characters and at most 20 characters.
  2. It must contain at least one lowercase letter, at least one uppercase letter, and at least one digit.
  3. It must NOT contain three repeating characters in a row ("...aaa..." is weak, but "...aa...a..." is strong, assuming other conditions are met).

Write a function strongPasswordChecker(s), that takes a string s as input, and return the MINIMUM change required to make s a strong password. If s is already strong, return 0.

Insertion, deletion or replace of any one character are all considered as one change.


The first thing I notice is that as simple sight this problem does not seems like one that can be solved by implementing complicated data structures, but, several instructions that must be followed sequentially in order to determine if the string given is strong enought. My firt aproach consist in implementing a method that takes the string `password` and tries to fit into every posibility.
