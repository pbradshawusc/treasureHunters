# Game Design Document: Treasure Hunters!

##Moving Objects _(All moving objects aside from Arrows will have 2 or 3 step animations along with movement)_:

  1. Treasure Hunter (player)
    - Movement: Horizontal and vertical, but only one at a time on arrow key presses 
    - Generation: Bottom of the screen in the same place every time the user loses a life or enters a temple
    - Sprites:
    - Credit: http://spritedatabase.net/files/snes/571/Sprite/Red.png 
  1. Cars/Logs/Alligators 
    - Movement: Horizontal one way, direction depending on row generated
    - Generation: Randomly at the left or right edge depending on row. All cars/logs/alligators in the same row will move the same direction at the same speed.
    - Sprites:
    - ![Car Left 1](./Images/Car Left 1.gif) 
    - ![Car Left 2](/home/cs102/Desktop/TreasureHunters!/Car Left 2.gif) 
    - ![Car Right 1](/home/cs102/Desktop/Treasure Hunters!/Car Right 1.gif)
    - ![Car Right 2](/home/cs102/Desktop/Treasure Hunters!/Car Right 2.gif)
    - Credit: http://spritedatabase.net/files/neogeo/836/Sprite/MSCar2.gif 
    - ![Log](/home/cs102/Desktop/Treasure Hunters!/Log.png)
    - Credit: http://www.swish-designs.co.uk/blog/?p=1331 
 
    - Credit: http://zeldapower.com/images/others/foe/sprites/Crocodile_snapping1.gif http://zeldapower.com/images/others/foe/sprites/Crocodile_swimming.gif 
  1. Holy Grail
    - Movement: Random horizontal and vertical at the same time, changes with timer. Moving randomly around the screen
    - Generation: Random off-screen and then moves onscreen
    - Note: Gives player extra life
    - Sprite:
    - Credit:  http://officialpetsociety.files.wordpress.com/2011/09/medieval-goblet.png 
  1. Guardians
    - Movement: Horizontal back and forth in their set boundaries (1-3 Guardians, covers whole horizontal boundary)
    - Generation: Random within their set boundaries at the beginning of a level/life
    - Note: Shoot Arrows vertically down the screen at random intervals within a set time range
    - Sprite:
    - Credit: http://spritedatabase.net/file/9197 
  1. Arrows 
    - Movement: Vertically down the screen at constant speed
    - Generation: On random intervals within a set time frame always at the location of the shooting Guardian
    - Sprite:
    - Credit: See Guardian
  1. Temples 
    - Movement: None
    - Generation: Always at the same places on the top of the screen
    - Note: 5 temples are the end goals for the treasure hunter
    - Sprite: 
    - Credit: http://images.wikia.com/kirby/en/images/d/d2/KEY_Pyramid_sprite.png 
  1. River 
    - Movement: None, just rushing water animation
    - Generation: Always in the same place
    - Note: Used for object detection of falling off of a log
    - Sprite:
    - Credit: http://img393.imageshack.us/img393/730/water6cx.png 
 
##Basic Functionality

  - Player moves the treasure hunter with the arrow keys: up, down, left, and right
    - One move per press, can’t just hold down
  - Trying to get treasure hunter into temple. 
    - Once a treasure hunter has entered a temple, a new treasure hunter cannot enter the same temple.
    - Total of 5 temples, once 3 have been entered, all are cleared.
  - To get to temple, must first dodge cars along a desert path; then must jump across logs to get to temple. 
    - All the while, the Guardians will be shooting Arrows.
    - If the player steps on a gator, then the player loses a life.
    - If the player gets hit by a car, then the player loses a life.
    - Losing a life will change the player sprite to a skull and crossbones, and then reset the player back to the start.
  - Player will start with three lives.
    - Holy Grails will appear randomly with a small chance throughout the game and if the user hits one then he/she will be given another life.
  - Game will have a timer, if the player does not make it to the temple within a certain time, a boulder will roll across the screen and kill the treasure hunter, causing the player to lose a life.
    - Timer will be the same for all levels.
  - When the player gets to a temple, he/she will earn points equal to the amount of time left times a difficulty factor.
    - Difficulty factor will start at 1.25 and be squared for every difficulty level. (1.25, 1.5625, 2.44140625, 5.96046448, 35.5271368, etc.)
    - Difficulty factor will increase with each level.
  - Each level will be getting the treasure hunter into an unoccupied temple 3 times. During all three times the speed of all objects will be the same.
    - When a level is completed, the user moves on to the next level, where everything moves faster.
    - This continues indefinitely until the user loses.
    - The user’s movement speed will also increase, but the limiting factor is the user’s reaction time. Thus after a certain point it will be impossible to beat the level.

##Object Detection:

  - For the player to be securely on a log, road, or temple, at least half of the player’s sprite must be on the log, road, or temple (as opposed to being on the river).
  - For the player to be hit by a Holy Grail, car, or Arrow, any overlap of the player’s sprite with the respective Holy Grail, car, or Arrow’s sprite will result in a collision.
  - For alligators, the player’s sprite must have at least 1/3 of overlap for a collision to be detected.

##Game Layout
###Opening Screen
  - Credits (Desert): http://spritedatabase.net/files/gameboy/732/Background/SK_ScorchingDesert.png 
###Game Screen
###Pause Screen

----

## Markdown
Markdown is a human-readable structured plain text format that is used to convert text into HTML. GitHub automatically renders Markdown into HTML.

This is a crash course on how to use Markdown. The following section will show you the plain text used to generate the document shown in the rendering section.

### Code

```
# Header 1
## Header 2
### Header 3
#### Header 4
##### Header 5

You can also write in **bold** or _italics_. You can also ~~strike through~~ or write inline `Code Segments`

>Blockquotes are done as such.

Just make sure to separate paragraphs with an emptyline. 
Otherwise, they are considered in the same paragraph.

You link to [Google](https://www.google.com) as such and lists are written has follows:
  1. First you indent with two empty spaces.
  1. Then, you use:
    * `1.` to signal an ordered (i.e. numbered) list, or
    * `*`, `-`, `+` to represent an unordered list.
      1. Make sure to maintain indentation
      1. As it is used to identify sub-lists
  1. Numbering and symboles don't matter as they are auto-generated later.

Tables are pretty easy to make:

| Tables        | Are           | Easy          |
| ------------- |:-------------:| -------------:|
| left-aligned  | centered      | right-aligned |
| header are    | bolded and    | centered      |
| zebra stripes | are neat      | 1             |


Images are added inline by using the following syntax
![alt text](http://octodex.github.com/images/Professortocat_v2.png "Image Title")
```

----

### Rendering
This section shows the rendering of the plain text above.

# Header 1
## Header 2
### Header 3
#### Header 4
##### Header 5

You can also write in **bold** or _italics_. You can also ~~strike through~~ or write inline `Code Segments`

>Blockquotes are done as such.

Just make sure to separate paragraphs with an emptyline. 
Otherwise, they are considered in the same paragraph.

You link to [Google](https://www.google.com) as such and lists are written has follows:
  1. First you indent with two empty spaces.
  1. Then, you use:
    * `1.` to signal an ordered (i.e. numbered) list, or
    * `*`, `-`, `+` to represent an unordered list.
      1. Make sure to maintain indentation
      1. As it is used to identify sub-lists
  1. Numbering and symboles don't matter as they are auto-generated later.

Tables are pretty easy to make:

| Tables        | Are           | Easy          |
| ------------- |:-------------:| -------------:|
| left-aligned  | centered      | right-aligned |
| header are    | bolded and    | centered      |
| zebra stripes | are neat      | 1             |


Images are added inline by using the following syntax
![alt text](http://octodex.github.com/images/Professortocat_v2.png "Image Title")

