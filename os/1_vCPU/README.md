# Notes
- fork = very simple. no args, just returns pid of child or 0 or -1 if error.

# Exercises
- Create a parent, which spawns a child.
- Same but now child also spawns a grandchild.
- Verify that parents ids are correctly set on all procs using cli tools
- See what happens if you kill: parent, child, grandchild
- Let child complete before parent: verify its a zombie
- Let parent complete before child: see what happens
- Run every single exec system call
- Run every single wait system call
- Create a parent process, which kills all of its children
- Create a child process, which kills all of its ancestors

Reading:
- Understand every argument of every exec system call
- Understand every argument of every wait system call

# New failure modes
## Fork
- Global process limit reached
- Per-user process limit reached
- Insufficient swap space for new process -> not enough for even metadata