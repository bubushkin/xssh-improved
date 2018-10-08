# xssh-improved

TOL

XBASE=/opt/xssh/USER/
XPATH=XBASE/bin

commands to fork
  adduser
  remuser
  copy
  move
  show
  export
  unexport
  

adduser:
  keys: -u USERNAME
  creates user under XBASE and creates var.env file for environment variables

remuser:
  keys: -u USERNAME
  deletes user from XBASE
 
copy:
  copies file from source to destination
move:
  same as copy, except it src is removed;
show:
  similar to "echo"
  -f FILENAME will work as cat

export:
  export -v will write a new env variable to user's var.env file
  e.g. export NEWVAR=somevalues
  appends to buffer for immadiate use
unexport:
  removes variable from a buffer
  
