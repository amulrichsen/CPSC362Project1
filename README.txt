Class 362 SWE Fundamentals
---------------------------------------
Team JAH & Members
=================
- John Margis
- Anette Ulrichsen

$VCS Project 3 – Merged
===========================
- This Project 3 merges changes from a repository root folder into a target project tree by 
checking if each folder and file exists while creating merge conflicts if a file is updated. 
On doing so it creates a manifest listing the command particulars, the date and time of the command. Each project source file
line gives a small description of what is inside along with the project folder relative
path. We also include an artifact ID with full file contents under a leaf folder, which
includes the file’s name. It also includes a label function that, given a manifest name and a target path, can create a new label, 
or given an established label name and target path, can create a new label. 
There is a check in function, which overwrites the current version of the repo from the project tree and generates a new manifest file. 
There is also a check out function, that creates a new repository based on a manifest file inside of the source repository.
Finally, there is the merge function, which merges changes from a repo into a previously checked out project tree.

File Includes With This Project
========================
- artifact.cpp Artifact implementation
- artifact.h Artifact header
- file.cpp File implementation
- file.h File header
- leaf.cpp Leaf implementation
- leaf.h Leaf header
- main.cpp Driver for create repo
- manifest.cpp Manifest implementation
- manifest.h Manifest header
- repo.cpp Repo implementation
- repo.h Repo header
- README This file

External Requirements
==================
NONE

Setup & Installation
===============
-This program does not require installation.
You should run the program in any C++ compiler or Linux device.

Features
=======
- When compiling and running the C++ files it requires C++17 standards, which this
program implements new features used up to C++17. Visit:
https://en.cppreference.com/w/cpp/compiler_support
- When compiling and running in Linux make sure to add –lstdc++fs option
Visit: https://stackoverflow.com/questions/44476810/build-project-with-
experimental-filesystem-using-cmake

Sample invocation & Results To See
===========================
- After Setup & Installation and Features added to user device you will be able to run
the program.
- First thing you will see:
COMMANDS:
create
check-in
check-out
label
merge

ENTER A COMMAND:
You can type an of the above commands to run. 
Create creates a repository from a project tree. 
Check in overwrites a repo from the project tree. 
Check out generates an older version of the repo from a manifest file. 
Label finds and adds a label inside of a repo manifest file. 
Merge updates a project tree with changes from a repo.
The program only runs once. If you would like to use multiple commands, you must run it multiple times.

CHECKOUT:
- Result should be a repository copy of the source tree, including an artifact under a
leaf folder and manifest for command particulars.

CHECK-IN:
- Result should be an updated repository at the target path, created from the project tree in the source path.

LABEL:
- Result should append L: LABEL NAME to the manifest and allow selection by label.

MERGE:
- Result should be an updated projec tree at the source path, updated from the repo in the target path.

TEST CASE DIRECTORY LISTINGS:
Note: Test case results located in tests folder within ZIP file.


Bugs
====
- When creating repo, you cannot create it in the same place as the source file.
- If a repo is created using an absolute path, check-in, check-out, and merge commands must also use an absolute path.
- If a repo is created using a relative path, check-in, check-out, and merge commands must also use a relative path.
