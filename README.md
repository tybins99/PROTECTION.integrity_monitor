____
# Migale Security Suite - File Integrity Monitor
### Revision date	: 2006/12/04
### email       	: cv.dev.cpp@gmail.com
##### Protection	: Beemeal Source Shadow (V1.0.0)
____

## __1. Introduction__

This tool permits to do the following things :
- create a snapshot of the state of all hard drives of a given computer.
- compare the state of the hard drives with the snapshot so that 
  differences can be noticed (if any) and analyzed.
It is particularly useful to create a honeypot system.

## __2. Detailed description__

This tool permits to monitor the following file types :
.exe, .dll, .sys, .com
Let's call this set of file types the relevant files.
The tool is able to look for the relevant files on all hard drives.
The tool first will have to create a snapshot of the hard drives and
store it into a database (stored in a file).
Then using this database, it will be able to notice 
the following differences :
- a relevant file was deleted.
- a new relevant file was created
- an existing relevant file was modified.

Notice that the tool supposes it was installed with the Migale Security
Suite, so that it will look for it's database path and other necessary 
paths using the registry.
If you have not installed the Migale security suite and you want to use
the tool, you will have to specify the following paths as command line
parameters :
- the database path (where to store the database)
- the NEW FILES path : where to copy new files
- the MODIFIED FILES path : where to copy files that have changed.

## __2.1. Operating modes__

There exists 2 different operating modes :
- manual mode
- automatic mode

In "manual mode", the user interacts with the tool using buttons and the 
tool answers by displaying status and warning/errors.

In "Automatic mode", the user gives some parameters to the tool as a
command line sequence of parameters so that the tool can perform any
sequence without human intervention. This is particularly useful if
you want to launch the application automatically each time you boot.

## __2.1.1 Manual mode__

In manual mode there are 3 relevant controls to consider :
- the "Create DB" button
- the "Check integrity" button
- the "Loop" checkbox

- The "Create DB" button permits you to create a snapshot of the state 
  of all hard drives of your computer. Notice that it may takes some time
  if you have a big hard drive.

- The "Check Integrity" button permits to compare the state of the hard
  drives with their respective state when the snapshot was created.

- The "Loop" checkbox permits to decide at any time to perform the 
  Integrity check in a loop, so that the tool becomes a kind of real
  time checker. That is to say it will restart checking after one
  check was completed. Notice that you may uncheck this checkbox at
  any time to stop the cycle, of course the check will complete, and then
  will stop instead of looping again if checkbox was unchecked meanwhile.

Notice that creating the database and checking the integrity can not
be performed concurently, it is logical because in order to check the
integrity you need a full database.

Notice that you can decide to stop the database creation, or the files
integrity checking at any time, However if you stop the database creation
before it finishes normally, you had better not launch a check, because
as the database is not complete, the tool will believe that many new files 
have appeared on your hard drive and will copy them all to the NEW FILE
folder, so the advice is : if you don't have any choice but stopping the
tool while database creation is in progress, don't forget to restart it 
later and let it finish

All the relevant files that have been created after the database creation
are copied to the folder that you either specified as a parameter at
startup (see automatic mode), or that were found using the registry
(the folders are displayed at startup).

All relevant files that have been modified after the database creation
are copied to the folder that you either specified as a parameter at
startup (see automatic mode), or that were found using the registry
(the folders are displayed at startup).


## __2.1.2 Automatic mode__

The automatic mode permits to avoid having to use the GUI to perform
an operation.
So you have to pass parameters to the tool when it starts (as under Unix)
The usage is as follows :

Usage: -db <path> -new <path> -modified <path> -create -check -auto <timeout_second>");
-db <path> : this flag permits to specify a path for the database");
             notice that if not specified, a default directory is used");
-new <path> : this flag permits to specify a path to save the new files");
              notice that if not specified, a default directory is used");
-modified <path>: this flag permits to specify a path to save the modified files");
-create: tells the program to create a new database, this is done once at program startup");
-check: tells the program to perform an integrity check, this step is performed after ");
        database creation if the flag -create is present, otherwise it is done first.");
        Also notice that this step is done only once, unless the flag -auto is specified");
		  in which case the check is performed in an infinite loop every TIMEOUT seconds");
-auto <timeout_second> : this flag tells the program to perform the check in an infinite loop");
                         the program sleeps during <timeout_second> seconds before launching");
                         a new check.");
                         Notice that the flag -check MUST be present if flag -auto is present");
                         The timeout is expressed in seconds.");


## __3. FAQ__

### __3.1 What is the method used to detect changes in a file ?__

The algorithm used is a 32 bytes CRC generated by a MD5 algorithm so that
even the slightest modification of a file can be detected.

### __3.2 Why does it sometimes take time to close the tool ?__

The tool is multithreaded, and to prevent from having database 
inconsistency the main thread just suggest to other threads to stop
as soon as possible, and then it is up to these other threads to stop
and as soon as they have stopped, they inform the main thread that then
decided to close the application.

### __3.3 why can't I have the -auto flag without the -check flag ?__

The -auto flag is a modifier of the behaviour of the -check flag, so 
you just can't modify a flag's behaviour when this flag is absent.

### __3.4 Can I pass command line parameters in any order ?__

Yes, the order does not matter, you can choose the order you want.

### __3.5 Why are there several steps when checking integrity ?__

The first step is to look of files that were deleted from hard drives.
The second steps is to look for files that are new, or were modified.
Furthermore the tool takes into account the number of hard drives you 
have to display the total number of steps remaining.

### __3.6 I have specified a timeout, but the tool displays a warning, why ?__

The timeout is expressed in seconds, if your timeout has a bad value 
(a letter instead of a number for example) or if it is greater than the
number of seconds in 24 hours, you will see a warning telling you that 
you might have made a mistake when typing the timeout.
