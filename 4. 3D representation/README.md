# 3D Representation
In order to create an interactive 3D representation, multiple steps are needed. We start in Blender for more animation centered tasks, and end the process in Unity for logic, control and interactivity.

## Unity script Architecture
current architecture:
![architecture of 3D](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/3.14%20image.png)

Video demonstration:

## Animation of factory parts
### 3D model handling:
Here is described our process to create "ready to use in Unity" objects from the .step files.

First, we installed the tool CAD Assistant from Open Cascade. This tool allows to open, preview an convert .step files. For Blender use, we export those files as a .glb . GLB files are openable in Blender. The model 3 has some of the VGR and all of the SLD module In the file structure, the SLD is contained mostly in the NAUO13.

### 3D model animation
This step follows the 3D model handling. We suppose we have a 3D file imported in Blender (.glb for example) and only one module is there. We'll use the pump activation as a case study.

First, we nee to set up rigging for our object: https://www.youtube.com/watch?v=zVhRKcL60NU

Rigging steps:

1. Make sure all the pieces moving together are parented to one object (can be a piece).
![3.15](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/3.15%20image.png)

2. Create an armature with a bone (or add a new bone to an already existing armature) and place it on the moving part. In order to make sure you see it, go to the Object data properties, then viewport, and check Show > In Front.
To move and transform the bone, you can use the G (Grab -- translation) R (Rotate) and S (Scale) keyboard shortcuts. If you want to limit those transformations to one axis, after selecting the tool, press down the axis name (X , Y and Z keys).
![3.16](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/3.16%20image.png)

3. Parent the armature to the object: Start by selecting the object, then hold shift and select the armature. Then press Ctrl+P and select the  option "Bone"
![3.17](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/3.17%20image.png)

We'll build animations for the module in Blender using the method showed in the video below.

https://www.youtube.com/watch?v=uWexElqDcaA

4. Open up a "dope sheet" window: right click in between the time line and the main view port, this should open the Area Options menu. Select horizontal split. With the new window, select with its top left button Animation > Dopesheet. You should see a new kind of timeline popping up instead of a second viewport. At last, set yourself in the action editor mode.
![3.18](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/3.18%20image.png)

5. Create a new action with the center button on this new window, and name it accordingly.
![3.19](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/3.19%20image.png)

6. Select your bone and get into pose mode on the viewport (Ctrl + tab or button on the upper left). Activate auto-keying by pressing the leftmost button on the timeline.
![3.20](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/3.20%20image.png)
Now we can start making the animation. The animation is based on "keyframes". Every keyframe holds constraints for the objects we can define. With auto keying, blender will create those constraints as we manipulate the object. But we need to make sure we're on the right frame when doing so. After fixing the constraints, Blender will interpolate the movement from one keyframe to another and generate positions for all frames. In this example, we'll make a linear translation, we need to fix constraints on only two frames: frame 0 and frame 50 (end of animation, could be something else).

7. Set the frame 0. There, there is just a translation, so we just need to make sure we initialize the coordinates (X,Y and Z) of the bone properly. Press G to grab, then press enter (the object should not move). With autokey, you should have a new line on the dopesheet, and every constraint should show when you display the transform of the bone.
![3.21](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/3.21%20image.png)

8. Set the frame 50. Make sure the frame you're on is 50 before operating. Grab your object (G), limit the movement to the X axis (X) and move it to its final position. A new keyframe should have been created on the dopesheet.
![3.22](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/3.22%20image.png)
Once this is done, remove auto-keying and don't forget to leave pose mode.

9. If you want to keep multiple animations stored for one single object, make sure you "protect" your current animation by assigning it to a fake user before closing blender. Click on the shield icon next to the name of the action in the dopesheet. Inactive and unprotected animations will not be saved in the project.
![3.23](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/3.23%20image.png)

10. Export your file as a .fbx

Those animations can be used in Unity on event triggers. (Unity version used: 2021.3.15f1)

11. Open the Unity project. Import the new file as a new Asset: Assets > Import New Asset. Then drag the prefab onto the scene to instantiate it if not already done.
If an older version of the file is there, delete it beforehand instantiated prefabs don't need to be deleted.

![3.24](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/3.24%20image.png)

12. Add an animator component to the instantiated prefab.
![3.25](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/3.25%20image.png)

13. Right click on the assets, and Create a new Animator Controller. Name it accordingly. Link the animator from the instance to this controller. Double click on it to open the animator editor.
![3.26](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/3.26%20image.png)

14. Drag the animation from the prefab into the editor. In this example, we'll just get it linked to the Start state so that it plays at the start of the scene.
![3.27](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/3.27%20image.png)
Hit the start button to launch the scene and check if everything's working properly. There we are, the piston moved once at the start of the scene. Now the main goal is to use the animator to trigger the animation from scripts and start linking it with the control layer of the system.

### 3D model control
This step goes after the 3D model animation step. The goal of this step is to start implementing control in the digital twin of the factory. We'll continue on the example of a piston (simple back and forth translation) for the SLD part.

This is inspired from the video [here](https://www.youtube.com/watch?v=tveRasxUabo/).

1. Create a new default state and call it "Empty" by right clicking the animator panel and selecting Create State > Empty. Set it as the default state from the start by right clicking it and selecting Set as Layer default state.
![3.28](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/3.28%20image.png)
![3.29](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/3.29%20image.png)

2. Duplicate the state you used before.
3. Rename the duplicate as "PullPiston0" and change its animation speed to -5.

By this point, you should have two "grey" blocks with an inspector status just like those:
![3.30](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/3.30%20image.png)
![3.31](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/3.31%20image.png)

4. Create transitions between your states:

- From empty to push
- From push to pull
 -From pull to empty

By this point you should have a structure just like this.
![3.32](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/3.32%20image.png)

5. Now we need to add conditions on those transitions. Right now, the states will just play one after the other, but that's not what we want, we want to trigger those transitions on specific timings. To do so, the first step is to create the Trigger parameters. On the top left of the animator select the parameters tab.
![3.33](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/3.33%20image.png)

6. Now add some parameters of type Trigger and name them accordingly. 7. Select the first transition (empty->push) by left-clicking on the arrow. 8. Add a condition to this transition, and set it to the pushTrigger you just created.
![3.34](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/3.34%20image.png)
Now, when the trigger will be used with the finite state machine in the "empty" state, the piston will enter the push state and start moving forward.

7. Add a condition on the push -> pull transition in the same way (just change the trigger used).

There's no need to add a condition on the third transition, we want to always go back to the empty state as soon as the pull state animation is finished.

Now that the animator is set up, we just need to trigger the triggers using a C# script. The C# script under needs to be added as a component at the same place as the animator is (aka on the SLD module object itself).

//Default imports
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

//Class definition, every script must extend the MonoBahaviour type from Unity
public class ControlAnimationPistons : MonoBehaviour
{
    
    private Animator animator;//script variable to store the other component of the object we want to interact with, there, its animator
    // Start is called before the first frame update
    void Start()
    {
		animator = this.GetComponent<Animator>();//assign the value of the animator component
    }

    // Update is called once per frame
    void Update()
    {
		if (animator != null) //check that there's an animator
		{
			if (Input.GetKeyDown(KeyCode.O))//check if the O letter key is pressed down
			{
				animator.SetTrigger("PushTrigger0");//set the trigger for the push transition
			}
			if (Input.GetKeyDown(KeyCode.P))
			{
				animator.SetTrigger("PullTrigger0");//set the trigger for the pull transition
			}
		}
    }
}

However, things can get more complicated than a single piston, and we want to manage some animations "independently" from each other. That's why Unity animator has a layer feature. In this example, we want to parallelize the control of the multiple pistons. We suppose we have three different animations in the fbx file, that each corresponds to a single piston.

- Go on the Layers tab in the animator top left corner, and add a new layer under the base layer we have.
- Name this layer according to the object it will control.
- Change its parameters. Here, we want it to have a full weight (our layers do not have any colliding impact zones, so we don't need to ponderate) and set its blending to additive. That means that the deformations of the armature (bones) made on this layer will add to those already made on the first layer. A A should appear next to the parameter wheel if the blending is properly changed.
![3.35](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/3.35%20image.png)

- Copy all the states in the first layer and paste them to the second layer (the state machine has the same topology for both pistons). 5. Update the values in the topology: make the empty state as the default state (orange), change transition triggers, change Motion of the active states.

Once this has been done with the two other pistons, we can check how it works by using the script below. This script is barely more complex than the one above, it triggers the second and third pistons one and two second after the first one.

For this final test, a couple of ameliorations have been made to make the animations more responsive: the two conditioned transitions are set to Has exit time = False. They are triggered whenever the previous animation is playing and not only at the end. Moreover, in the script, opposite triggers reset each other. That means that there are no "stored" triggers in the system: if pressing once O while the system is in the push state, the trigger is set to true, and as soon as the empty state is reached back, it will go to the push state. By adding a reset when pressing P, we're sure that the O trigger is off when we exit the push state.

[ControlAnimationPistons.cs](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/4.%203D%20representation/ControlAnimationPistons.cs/)

Video demonstration:

## Simulating the factory functionning in Unity
In order to make the Digital Twin "move" when the factory "moves" then we need to share the information between the different software and give the 3D-representation some instructions through scripts and methods.

We were advised to add some augmented reality to our simulation, thus, when an element crosses a detector, the detctor changes its color to yellow (which makes the real place of the element even more understandable in the digital twin).

In our module (SLD), an element moves on the conveyer belt, in the Arduino Code we used spatial position with pulses since the motor might not be regular and it was more reliable to use space position than time position. However, in Unity we used time movement, when the motor is "on" then the element moves at a given speed (empirically calculated). This method is not perfect, however it is much more simple to implement.

To show the elements in the factory, we created some cylinders and we put them in a file "Elements" in the arborescence. The cylinders with associated colors correspond to the elements in their compartment which we show or hide whether the associated detector is activated or not. Then we use the element "Cylinder" to show the moving element on the conveyer belt, to do so we use a little trick, we hide the element at the begining of the simulation, then we create a copy when an element is detected at the input of the module and we make that copy move. This allows us to make several runs within the module without any issues.
![3.36](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/3.36%20UnityElement.png)

Note : we didn't make the animation for the fall of an element in its compartment both because we didn't know how to do it and because it might show false information (the element can be pushed but remains on the conveyer belt).

## Converting Unity project in executable
What is interesting in Unity is that you can develop your animations and stuff on one hand and then use it in an executable whenever and wherever you want (without needing unity installed). However, there is a little process to follow in order to do it clean :

- once you finished creating your "game", go to "File" > "Build Settings".
- then select Linux (or the exploitation system you want).
- if you want a specific width and height of window for your game, go to "Player Settings" > "Player" > "Resolution and Presentation" and then select the values you wish.
- then go back to the "Build Settings" window and select "Build", the operation will take a few moments.
![3.37](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/3.37%20BuildSettings.png)

Note : it is possible to do the download on WebGL HTML 5 instead of executable but you will then need the appropriate module in Unity (this note is for the transfer on a server).
