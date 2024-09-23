# pipex

## Description

`pipex` is a project designed to simulate the shell pipe `|` operation in C. It allows chaining of multiple commands by redirecting the output of one command as input to the next. This project was created as part of the École 42 curriculum to practice handling pipes, file descriptors, and process management in C.

## Features

- Simulates the behavior of a Unix pipe `|`.
- Executes two commands, passing the output of the first as input to the second.
- Handles file redirection with input and output files.
- Manages errors gracefully, such as invalid commands or inaccessible files.

## Compilation and Usage

You can compile the project using the provided `Makefile`. To compile the `pipex` executable, simply run:

```bash
make
```

## Project Structure

- `pipex.c`: Main program that handles command execution using pipes.
- `get_paths.c`: Retrieves and parses the environment paths for commands.
- `pipex.h`: Header file containing function prototypes and includes.
- `minilib/`: Contains various utility functions like `ft_split`, `ft_strdup`, `ft_strjoin`, etc.
- `Makefile`: Used for compiling the program and managing build targets.

## How to Use

Once compiled, run the program using the following format:
```bash
./pipex infile "cmd1" "cmd2" outfile
```

- `infile`: The file whose content will be passed to the first command.
- `cmd1`: The first command to execute.
- `cmd2`: The second command to execute.
- `outfile`: The file where the output of `cmd2` will be stored.

Example:
```bash
./pipex infile "ls -l" "grep pipex" outfile
```
## Author

Project developed by [Emin A.](https://github.com/emayia) as part of the École 42 curriculum.