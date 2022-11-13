# get_next_line
project for ecole 42

In this project you need to write function that reads a string from a file descriptor.  
Reads the size of BUFFER_SIZE and writes it to the string that it allocates,  
also next read must start from the same place, so you can use this function in a loop.  
  
Bonus part: it should only use one static varible and should work with different  
file descriptors at the same time.
  
* You can see the full assignment here [subject](https://github.com/cbridget42/gnl_42/blob/main/subject/en.subject.pdf)
* Coding style: [norminette](https://github.com/cbridget42/gnl_42/blob/main/subject/en.norm.pdf)
  
### Usage:
* first you need to download the repository and compile the code! To do this, run:
	```bash
	git clone git@github.com:cbridget42/gnl_42.git
	cd gnl_42
	```
* here you have all the necessary files.
	+ to use it you need to add get_next_line.h header to your project.
	+ compile your project with .c files from the root of this repo.
* You can compile it with flag -D BUFFER_SIZE='your buff size'!
  
### Tests:
* Mandatory part
![image](https://github.com/cbridget42/gnl_42/blob/main/images/Screenshot%20from%202022-11-13%2018-53-57.png)
* Bonus part
![image](https://github.com/cbridget42/gnl_42/blob/main/images/Screenshot%20from%202022-11-13%2018-55-32.png)
  
### final score:
![image](https://github.com/cbridget42/gnl_42/blob/main/images/Screenshot%20from%202022-11-13%2018-44-42.png)
  
