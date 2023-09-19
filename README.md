# Get Next Line

## What is it?
This project consists of a function that reads a line from a file descriptor and returns it.  
If it is called in a loop, it must read the entire file without losing the reference.

**Succeeded with 115%**

## Skills
- Algorithms & AI
- Imperative programming
- Rigor
- Unix logic


## How to use it
Requirements:
```shell
sudo apt install clang
```

Then you will need a C program that has access to a file descriptor, using open in a file, for example:
```c
int main(int argc, char **argv)
{
	int	fd;
	char	*line; // Where the line will be stored

	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1);
	{
		printf("%s", line);
		free(line); // Because the line is allocated
	}
	return (0);
}
```
The return values are 1 (for line read), 0 (for EOF) and -1 (for error). So you can call it in a loop to print the entire file.

After that, compile it, defining the buffer size.
```c
clang -D BUFFER_SIZE=10 main.c get_next_line.c get_next_line_utils.c
```

And run it!
```c
./a.out text.txt
```
- The bonus version works the same, but it can handle multiple file descriptors.

## Found any bugs?
Feel free to contact me or create an issue!

## License
This project is licensed under the GNU General Public License v3.0 - see the [COPYING](https://github.com/hde-oliv/get_next_line/blob/master/COPYING) file for details.
