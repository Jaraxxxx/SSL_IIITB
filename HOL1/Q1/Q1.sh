#!/usr/bin/bash
# Q.1 Create the following types of a files using 
#   (i) shell command (ii) system call    
#   a. soft link (symlink system call)    
#   b. hard link (link system call)    
#   c. FIFO (mkfifo Library Function or mknod system call)

hard_l="hard"
soft_l="soft"
file_name="./Employee_Record.sh"
ln -s "$file_name" "$soft_l"
ln "$file_name" "$hard_l"
ls -l 

function cleanup {
  rm -rf "./Employee_Record.sh" 
  rm "$soft_l" "$hard_l"
}

trap cleanup EXIT