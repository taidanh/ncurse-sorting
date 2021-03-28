# NCurses Sorting Visualizer
Visualizer with options to show sorts for bubble, shell, 
quick and heap sorts. Also scales to terminal size.

## Build
You can build the program by running `make`

## Options
   - a              Enable all sorts.
   - b              Enable Bubble Sort.
   - s              Enable Shell Sort.
   - q              Enable Quick Sort.
   - h              Enable Heap Sort.
   - r seed         Specify random seed.

> EX: `./sorting -h -r 1337` will run heap sort with a seed of 1337.
> This is the output:

![heap](https://user-images.githubusercontent.com/65222208/112743300-f672c280-8f4a-11eb-83e3-19f1dd70929c.gif)
