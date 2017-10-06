# Stopwatch

This program is completely messed up now.

Basically, this program lets you create topics and record the amount of time you spend on topics
I was going to incoroporate some statistics for better analysis of your spent time but I didn't

I had a bug that caused the amount of time accumulated to be negative.
I thought it was an overflow problem and I  think it is.
I think the problem lies in adding all the spent time spent on a topic and causing the variable to overflow

I tried to implement a solution where the recorded amount of time is saved not in milliseconds
but in parts of a second

for instance

1000 milliseconds = 1 second 
.001 second = 1 millisecond

Even if this solution worked the way it should. It might not of solved the problem
because floating point precision can only be so precise.
