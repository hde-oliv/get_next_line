# Get Next Line

## Table of Contents

1.  [What is it](#orgf9d5865)
2.  [Skills](#org561ad69)
3.  [My grade](#org6eadf3b)
4.  [How to use it](#orgc749540)
5.  [Found a problem?](#org2eb15ed)



<a id="orgf9d5865"></a>

## What is it

This project consists on a function that reads a line from a file descriptor and returns it, if it is called in a loop it must read the entire file without losing the reference.


<a id="org561ad69"></a>

## Skills

-   Algorithms & AI
-   Imperative programming
-   Rigor
-   Unix logic


<a id="org6eadf3b"></a>

## My grade

Succeeded with 115%


<a id="orgc749540"></a>

## How to use it

First you will need a main function that have access to a file descriptor, using open for example:

    int main(int argc, char **argv)
    {
    	int	fd;
    	char	*line; // Where the line will be stored
    
    	fd = open(argv[1], O_RDONLY);
    	...

Its return values are 1 (for line read), 0 (for EOF) and -1 (for error). So you can call it in a loop to print the entire file.

    	...
    	while (get_next_line(fd, &line) == 1);
    	{
    		printf("%s", line);
    		free(line); // Because the line is allocated on heap
    	}
		return (0);
	}

After that compile it with the get_next_line_utils file

    clang main.c get_next_line.c get_next_line_utils.c

Voilà!

OBS: The bonus version works pretty much the same but works with multiple fd calls.


<a id="org2eb15ed"></a>

## Found a problem?

Feel free to contact me or create an issue.

##### Licensed under GPLv3



