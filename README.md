# CS 202 Semester Project (WOO)
## Group Members!

- Aaron Garza
- Garrett Weinert

## Responsibilities:
#### Garrett W. 
- Creating classes to identify and load files from a directory
- Creating user interface for user to input a directory and manage wav files
- Creating a CSV exporter
#### Aaron G. 
- Creating class to read/write wav files of varying types (mono/stereo and varying bit depth)
- Creating classes to add audio effects to loaded wav files
- Creating methods to modify the metadata of a wav file

## Design
![Software_Design (4)](https://user-images.githubusercontent.com/70527694/117069921-ef756780-ace1-11eb-9485-d84047a201db.jpg)


Our design uses a CLI for the user to access the various functions the program offers that can be operated. Using the CLI, the user may load in the Wav files from an inputted directory. After the files are loaded in, the user can select either to process a particular wav file, or to edit the metadata of a particular wav file using the meta data type. Once the meta-data desired is selected and changed, the user can export the data to a csv file. Once the user is finished, they can exit the application using an "exit" command.


## Challenges encountered:
- Choosing the best method by which wav files should be handled depending on technical data
- Organizing work among the team in an online environment where communication is made more difficult
