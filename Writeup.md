# **PID Controller Project**

[//]: # (Image References)

[image1]: ./md_images/proportional_gain.png "Proportional Gain"
[image2]: ./md_images/integral_gain.png "Integral Gain"
[image3]: ./md_images/differential_gain.png "Differential Gain"

### 1.	Describe the effect each of the P, I, D components had in your implementation.

**P – proportional gain**

This component is proportional to the Cross Track Error (CTE), defined as the “distance and direction right or left between the car and the desired track”. It steers the car, in proportion and opposite to the CTE, towards the lane centreline (or reference trajectory) to reduce the CTE.

That is, if the CTE is small and the car is slightly on the left/right to the lane centreline (i.e. small steering angle), the car will be steered slightly to the right/left respectively. Similarly, if the CTE is large and the car is on the outermost left/right to the lane centreline (i.e. large steering angle), the car will be steered much more to the right/left respectively. 

The proportional component is given by:

![alt text][image1]

where K<sub>p</sub> is the proportional coefficient

**I – integral gain**

This component is the sum of CTE observed, counteracting the systematic biases in CTE which prevent the car from reaching the lane centerline using the PD controller. An example of systematic bias is steering drift. 

The integral component is given by:

![alt text][image2]

where K<sub>i</sub> is the integral coefficient


**D – differential gain**

This component counteracts the oscillations/overshoots from the P component, allowing the car to approach the lane centreline gracefully without oscillations. 

The differential component is given by:

![alt text][image3]

where K<sub>d</sub> is the differential coefficient

### 2. Describe how the final hyperparameters were chosen.

The final hyperparameters (P, I, D coefficients) are manually tuned in the following sequence:
1. P controller is used for driving. However, the car starts to overshoot 12 seconds after starting and drives off the track subsequently. [Link](https://www.dropbox.com/s/j9soshpdfkz68ei/PSteer.mp4?dl=0) to the video.
2. PD controller is used to counteract the overshoots from the P controller. Though the car stays on the track, it swerves out of the track at times, especially near the sharp turns after the bridge. [Link](https://www.dropbox.com/s/8u2urcyth1igpdb/PDSteer.mp4?dl=0) to the video.
3. PID controller is used to counteract the biases. This improves the control of the car near the sharp turns after the bridge. [Link](https://www.dropbox.com/s/ylseg10zdtklb9w/PIDSteer.mp4?dl=0) to the video.
4. P controller for throttle is added to control the speed of the car. [Link](https://www.dropbox.com/s/0yzqmdedb51l2tr/PThrottle.mp4?dl=0) to the video.

The parameters are then fine-tuned to minimize the CTE at 35 mph on a single track lap. The final parameters of the PID controllers are
* PID for Steering – 0.132 : 0.002 : 3.05
* PID for Throttle – 0.4 : 0.0 : 0.0 

Here is the [link](https://www.dropbox.com/s/ggxidy11vyivoui/Final.mp4?dl=0) for the video result.