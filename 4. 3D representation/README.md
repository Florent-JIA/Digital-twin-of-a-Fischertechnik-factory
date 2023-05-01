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

## Simulating the factory functionning in Unity

## Converting Unity project in executable
