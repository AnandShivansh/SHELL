-----------------------------------
----------Shivansh Anand-----------
------------2018101086-------------

1. Display requirement:

	Username using 'getenv'
	Hostname using 'gethostname'
	Current directory using 'getcwd'

2. Built-in commands:

	cd: using 'chdir'
	pwd: using 'getcwd'
	echo: using 'printf'

3. ls command:

	used 'strtok' to get arguments
	used 'opendir' to open a directory using 'while' loop
	used 'stat' command to get file info
	used 'printf' to display details

4. System commands:

	used 'fork' to start a new process
	fg: parent waits for child to execute using 'wait' command
	bg: parent does not wait
	used 'execvp' to execute system commands

5. pinfo:

	if no pid is given replace 'pid' with 'self'
	read file '/proc/pid/stat' for pid, status and virtual
		memory used.
	read the link to file '/proc/pid/exe' to get executable.

6. Finished bg processes:
	
	maintained an array of all bg started processes.
	after executing all commands everytime checking if the
		process exists or not by opening '/proc/pid' directory.
	printing the exited processes using 'printf'