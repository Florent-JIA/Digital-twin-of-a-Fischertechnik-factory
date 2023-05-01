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
		if (animator != null)
		{
			if (Input.GetKeyDown(KeyCode.O))
			{
				Invoke( "TriggerFirstPush",0.0f);
				Invoke( "TriggerSecondPush",1.0f);
				Invoke( "TriggerThirdPush",2.0f);
			}
			if (Input.GetKeyDown(KeyCode.P))
			{
				Invoke( "TriggerFirstPull",0.0f);
				Invoke( "TriggerSecondPull",1.0f);
				Invoke( "TriggerThirdPull",2.0f);
			}
		}
    }

	//Push animations
	void TriggerFirstPush()
	{
		animator.ResetTrigger("PullTrigger0");	
		animator.SetTrigger("PushTrigger0");
	}
	void TriggerSecondPush()
	{
		animator.ResetTrigger("PullTrigger1");
		animator.SetTrigger("PushTrigger1");
	}	
	void TriggerThirdPush()
	{
		animator.ResetTrigger("PullTrigger2");
		animator.SetTrigger("PushTrigger2");
	}

	//Pull animations
	void TriggerFirstPull()
	{
		animator.ResetTrigger("PushTrigger0");	
		animator.SetTrigger("PullTrigger0");
	}
	void TriggerSecondPull()
	{
		animator.ResetTrigger("PushTrigger1");
		animator.SetTrigger("PullTrigger1");
	}
	void TriggerThirdPull()
	{
		animator.ResetTrigger("PushTrigger2");
		animator.SetTrigger("PullTrigger2");
	}
}
