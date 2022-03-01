# cub3D
This is the second graphics project at [42](42sp.org.br), our first RayCaster with miniLibX.

### What is cub3D?
Cub3D is a team project at [42](42sp.org.br) that asks us to create a "3D" game engine with [miniLibX](https://github.com/42Paris/minilibx-linux). This project is inspired by the world-famous 90's game [Wolfenstein 3D](https://pt.wikipedia.org/wiki/Wolfenstein_3D), which was the first [FPS](https://en.wikipedia.org/wiki/First-person_shooter#:~:text=First%2Dperson%20shooter%20(FPS),in%20a%20three%2Ddimensional%20space.) ever. The objective of this project is to deep dive into the mathematical concepts behind the [ray-casting algorithm](https://en.wikipedia.org/wiki/Ray_casting) such as calculating distances, height, sprite locations and field of view to create a projection using primarily [trigonometry](https://en.wikipedia.org/wiki/Trigonometry).

### Gameplay
![alt text](./images/so_long_gameplay.gif)

### Badge
<img src="./images/cub3dm.png" width="150" height="150"/>

#### Skills
- Rigor
- Imperative programming
- Graphics
- Algorithms & AI

#### My grade
<img src="./images/score2.png" width="150" height="150"/>


## Getting started
**Follow the steps below**
```bash
# Requirements: X11 miscellaneous extensions library and Utility functions from BSD
# To install the dependencies, open the terminal window and write
sudo apt-get install libxext-dev libbsd-dev

# Clone the project and access the folder
git clone https://github.com/wwwwelton/cub3D && cd cub3D/

# Run make so you can build the game
make bonus

# Run the game with one of these maps as an argument
./cub3D assets/maps/bonus/maze.cub
./cub3D assets/maps/bonus/dust2.cub

# Clean output objects with
make fclean

# Well done!
```

**Game Controller Keys**

**Move player:** W, A, S, D
**Move camera:** 🡡, 🡠, 🡣, 🡢
**Interact:** E
**Shoot:** Left shift or left mouse button
**Menu:** ESC

## Updating

The project is regularly updated with bug fixes and code optimization.

## 📝 License

This project is licensed under the GNU General Public License v3.0 - see the [LICENSE](LICENSE) file for details.

---

Made by:
João Rodriguez 👋 [See my Github](https://github.com/VLN37)<br />Welton Leite 👋 [See my linkedin](https://www.linkedin.com/in/welton-leite-b3492985/)
