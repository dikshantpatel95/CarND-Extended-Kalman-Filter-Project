# Extended Kalman Filter Project Starter Code
Self-Driving Car Engineer Nanodegree Program

In this project you will utilize a kalman filter to estimate the state of a moving object of interest with noisy lidar and radar measurements. Passing the project requires obtaining RMSE values that are lower than the tolerance outlined in the project rubric.  Passing the project requires obtaining RMSE values that are lower that the tolerance outlined in the project rubric: px = 0.11, py = 0.11, vx = 0.52, vy = 0.52.

To test it, [Term 2 Simulator](https://github.com/udacity/self-driving-car-sim/releases) need to be used. The latest version of `main.cpp` used to run this project without the simulator can be found [here](https://github.com/udacity/CarND-Extended-Kalman-Filter-Project/blob/06cbc9967bc62592723eef99b8c8035e4a22ea7b/src/main.cpp).

If you are looking for Udacity's started code project, you can find it [here](https://github.com/udacity/CarND-Extended-Kalman-Filter-Project).


Dependencies
------------

- [Udacity's Self Driving Car Simulator](https://github.com/udacity/self-driving-car-sim/releases)
- [`cmake >= 3.5`](https://cmake.org/install/)
- `make >= 4.1` (Linux / [Mac](https://developer.apple.com/xcode/features/)), [`3.81` (Windows)](http://gnuwin32.sourceforge.net/packages/make.htm)
- `gcc/g++ >= 5.4` (Linux / [Mac](https://developer.apple.com/xcode/features/)), [`MinGW` (Windows)](http://www.mingw.org/)
- [`uWebSockets` commit `e94b6e1`](https://github.com/uWebSockets/uWebSockets). See the following section for installation instructions and additional details.
- [`Eigen`](http://eigen.tuxfamily.org/index.php?title=Main_Page). This is already part of the repo so you shouldn't have to worry about it.


Installation
------------

This repository includes two files that can be used to set up and install [uWebSocketIO](https://github.com/uWebSockets/uWebSockets):

- `install-mac.sh` for Mac.
- `install-ubuntu`for either Linux or [Windows 10 Bash on Ubuntu](https://www.howtogeek.com/249966/how-to-install-and-use-the-linux-bash-shell-on-windows-10/) (**please, make sure it is updated**).

For Windows, Docker or VMware coulso also be used as explained in the [course lectures](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/16cf4a78-4fc7-49e1-8621-3450ca938b77). Details about enviroment setup can also be found there.

If you install from source, checkout to commit `e94b6e1`, as some function signatures have changed in `v0.14.x`:

    git clone https://github.com/uWebSockets/uWebSockets
    cd uWebSockets
    git checkout e94b6e1

See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.


Build & Run
-----------

Once the install is complete, the main program can be built and run by doing the following from the project top directory:

1. Create a build directory and navigate to it: `mkdir build && cd build`
2. Compile the project: `cmake .. && make`
3. Run it: `./EKF`

Or, all together (from inside the `build` directory): `clear && cmake .. && make && ./EKF`

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d).



###Running the Filter
From the build directory, execute ./ExtendedKF. The output should be:
```python
Listening to port 4567
Connected!!!
```
As you can see, the simulator connect to it right away.
####The following is an image of the simulator: running with dataset 1

<img src="https://github.com/dikshantpatel95/CarND-Extended-Kalman-Filter-Project/blob/master/images/data1.JPG">


####The following is an image of the simulator: running with dataset 2


<img src="https://github.com/dikshantpatel95/CarND-Extended-Kalman-Filter-Project/blob/master/images/data2.JPG">
          
          
   
 # [Rubric](https://review.udacity.com/#!/rubrics/748/view) points

## Compiling

### Your code should compile

The code compiles without errors. I did change the [CMackeLists.txt](./CMakeLists.txt) to add the creation of the `./Tests`. I don't think this will create incompatibilities with other platforms, but I only test it on Mac OS.

## Accuracy

### px, py, vx, vy output coordinates must have an RMSE <= [.11, .11, 0.52, 0.52] when using the file: "obj_pose-laser-radar-synthetic-input.txt which is the same data file the simulator uses for Dataset 1"

The EKF accuracy was:

- Dataset 1 : RMSE <= [0.0973, 0.855, 0.4513, 0.4399]
- Dataset 2 : RMSE <= [0.0732, 0.0963, 0.3812, 0.4778]

## Following the Correct Algorithm

### Your Sensor Fusion algorithm follows the general processing flow as taught in the preceding lessons.

The Kalman filter implementation can be found [src/kalman_filter.cpp](./src/kalman_filter.cpp) and it is used to predict at [src/FusionEKF.cpp](./src/kalman_filter.cpp#L147) line 147 and to update line 159 to 169.

### Your Kalman Filter algorithm handles the first measurements appropriately.

The first measurement is handled at [src/FusionEKF.cpp](./src/kalman_filter.cpp#L61) from line 61 to line 107.

### Your Kalman Filter algorithm first predicts then updates.

The predict operation could be found at [src/FusionEKF.cpp](./src/kalman_filter.cpp#L147) line 147 and the update operation from line 159 to 169 of the same file.

### Your Kalman Filter can handle radar and lidar measurements.

Different type of measurements are handled in two places in [src/FusionEKF.cpp](./src/kalman_filter.cpp):

- For the first measurement from line 61 to line 107.
- For the update part from line 159 to 169.




   
