# Overview

Have you ever wished that chess made less sense? And had more rules? And even more layers of strategy? Look no more, and behold: Vitrea!

Vitrea teaches players about gene inheritence as it allows players to freely combine and breed chess pieces to make horrible atrocities, and even possibly commit war crimes. Players will create genetic super soldiers, assemble an army, and battle their opponents in riveting turn-based chess combat.

# Software Overview

## The Board

The Board script handles the gameplay logic and movement of peices. The GenerateBoard script creates the board and an array of hitboxes (containing a hitbox script), which communicate to the board user input. The Board script then loads all the pieces from our local database, creates the corresponding Piece scripts, and places them on the board.

## The Breeder

The Breeder (or BreedingBehavior) script manipulates instances of the Piece class and (with help from the local database,) creates new Piece instances. In particular, it works with the Abilities and Appearance classes (defined in the corresponding scripts.)

# Development Environment

Unity v. 2020.2.3f1
Built with .Net 4.x
Using TextMeshPro
Written in C# with SQLite

# Collaborators

* [Brendan Koetting](https://github.com/Bren585)
* [Joshua Pettingill](https://github.com/JPNobody)
* [Eli Jukes](https://github.com/JukeOfHazzard)
* [Nicholas Cable](https://github.com/watercable76)
* [Elijah Harrison](https://github.com/ehrrsn7)


# Useful Websites

* [C# Official Documentation](docs.microsoft.com)
* [Unity Official Documentation](docs.unity3d.com)
* [Offical TMP Documentation](http://digitalnativestudios.com/textmeshpro/docs/)
* [Downloading C# to VS Code](https://code.visualstudio.com/docs/languages/csharp)  
* [C# Tutorial](https://docs.microsoft.com/en-us/dotnet/core/tutorials/with-visual-studio-code)  
* [More C#](https://docs.microsoft.com/en-us/dotnet/csharp/tour-of-csharp/)  
* [sqlite3 commands](https://docs.microsoft.com/en-us/dotnet/api/microsoft.data.sqlite?view=msdata-sqlite-5.0.0)
* [LinkedIn Learning](https://www.linkedin.com/learning/learning-c-sharp-3/a-hello-world-application?u=2153100)

# Future Work

* Connect external color bands of pieces to internal color genes
* Complete onHover functionality on game board screen
* Complete Breeding Screen
* Create Gamemode Selector
* Create a Story Mode.
* Balance the game (Wow this game is broken)
