# Craftus 3D Reloaded

It's been a while since I started developing this version of Craftus. I started to do a rewrite, because the old Craftus was beyond fixable. Probably 15% is copied from the old Craftus the remaining part is rewritten.

![](https://raw.githubusercontent.com/wiki/RSDuck/craftus_reloaded/screenshots/5.png)|![](https://raw.githubusercontent.com/wiki/RSDuck/craftus_reloaded/screenshots/6.png)
----|----
![](https://raw.githubusercontent.com/wiki/RSDuck/craftus_reloaded/screenshots/1.png)|![](https://raw.githubusercontent.com/wiki/RSDuck/craftus_reloaded/screenshots/4.png)


## Features

* An infinte world(in theory)
* An awesome flat world
* Blocks, of multiple variants, can be broken and placed down to build structures
* Saving and loading the world
* Clouds and menus

## Known bugs

* ~~I experienced once, that blocks, which are newly placed in a specific chunk weren't rendered anymore, but blocks placed in another chunk were, but I couldn't reproduce this bug. Maybe it's related to old savefiles~~ I hope I fixed this bug, because I couldn't find a way to reproduce it.
* ~~Making a screenshot with Luma Rosalina menu leads to crash~~ Somehow this doesn't happen anymore

## Credits
* People who made 3DS homebrew possible
    * Especially smea for 3dscraft which is good place for ~~stealing ideas~~ inspiration
    * Contributors of the 3dbrew.org wiki and ctrulib
    * Fincs for citro3d
    * More people I forgot about, even though I extended this list multiple times
* XSSheep, for the textures, taken from his [resourcepack](http://www.minecraftforum.net/forums/mapping-and-modding/resource-packs/1242533-pixel-perfection-now-with-polar-bears-1-11) which is licensed under [CC BY-SA](https://creativecommons.org/licenses/by-sa/4.0/)
* Tommaso Checchi, for his [culling algorithm](https://tomcc.github.io/2014/08/31/visibility-1.html), orginally developed for the use in MC PE
* Of course all other MC devs, how could I forget them?
* All people who worked on the libraries Craftus is depending on(see the dependencies folder)