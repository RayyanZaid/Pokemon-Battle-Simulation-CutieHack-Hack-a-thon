# Pokemon-Battle-Simulation
A text-based Pokemon Battle with a couple of personal twists.


## My Inspiration

I have been an avid Pokemon fan ever since I got a DSi (I think I was 6 years old)
When playing as a child, I always disliked the fact that a 1v1 Pokemon battle was mostly dependent on luck since:
  1. Certain Pokemon types are advantageous
  2. You are stuck with a certain move set
  3. One player always attacks first, giving them the advantage 


So, my mindset going into this was to try to eliminate the factor of luck in the Pokemon battle. 
I did this by:
  1. Giving each Pokemon some moves that are of different types (so that if the Pokemon is ever at a type disadvantage, it will have other options)
  2. Allowing each player to choose their move set 
  3. Both Pokemon attack at the same time


# What it does

This Battle Simulation is exactly what it sounds like, it puts 2 players in a 1v1 Pokemon Battle. The game continues on a loop, each player strategically selecting moves until either Pokemon or both get to 0 health. At that point, a winner or tie is declared and the program ends.


# How it was done

Overall, I got this done solely from the knowledge I amassed in the last month of c++ programming I did in my introductory comp sci class.
I utilized one outside library that allowed me to make it so my text displayed char by char (so I could get an authentic Pokemon feel).

Going into the program, I created 2 classes and 5 global functions in order to help make this program easily changeable (You can add more players and pokemon pretty easily since it is all object-oriented).

Class #1: The Pokemon Class

In this class, I included the components of each Pokemon: name, type, health, and a move-set (included as a vector). This allowed for me to do things such as change Pokemon health after every attack, correctly account for type adv. and disadvantages, and just overall helped make the program more organized and accessible to others.

 Class #2: The Moves Class

The Moves class is used solely to fill up a constructor argument in the Pokemon class. Instead of declaring the moves inside the Pokemon class, I created a separate class and then used a vector to assign the moves to each Pokemon based on what the user inputs. 

## The program as a whole

The whole backbone of this program is data from my text files. These text files include a list of pokemon (and their components) as well as a list of moves with their components. All of this was copy-pasted from a website, and I adjusted my input stream formatting to accommodate to the website formatting. I used lots of complex algorithms in my Battle Simulator class such as for loops within while loops and even more for and while loops within them to ensure that the program does not crash. For example, I create a while loop during the move selection that keeps on iterating until the user inputs a valid move from the list of moves. Inside this while loop, I had to check whether for the whole list of moves, the name of the move (move.getName()) was the same as the string that the user input. 



## Challenges I ran into
The most difficult challenge I ran into was deciding how to implement the type advantage and disadvantage function. I think this was difficult mainly because there was an easier alternative that would have taken longer (I input every single type of the Pokemon and the move being used against it and then determine whether the move will be more or less effective).


## Accomplishments that I am proud of

I was able to overcome the aforementioned challenge and discover an extremely more efficient way to implement the type advantage function. After a little bit of researching and learning about 2D arrays, I realized that I could use an online table (picture attached) and utilize my Pokemon and Move classes to access "double" data within that 2D array that would be multiplied to the move damage depending on the results from the data table.

I am also proud of my logic implementation in my battle simulation function

## What I learned

I learned and became a lot more comfortable using file input and utilizing data from outside sources to make my programming much easier.
I also became more confident with incorporating multiple classes within each other.


## The future of this project 

Looking to implement a couple more things that would make the project more interesting
1. Adding a double battle feature (2v2s)
2. Creating a round-based system so that if players want to rematch each other, they will not have to recompile the code. Also, there could be a certain round number so that the winner isn't decided in one round.
3. I would also like to add more Pokemon to my program. Right now, I only have 5. It is extremely easy for anyone to add Pokemon to it (it's just really time-consuming to find a fair move set).
4. I would like to incorporate more specifics into this such as the moves that heal the user, moves that increase a Pokemon's attack and defense power, etc.

