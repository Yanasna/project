using UnityEngine;
using System.Collections;
using System.Collections.Generic;
public class Main_Camera : MonoBehaviour
{
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        
    }
   public float cameraSpeed = 5.0f;

    public GameObject Main_Character;
   
    // Update is called once per frame
    void Update()
    {
        Vector3 dir = Main_Character.transform.position - this.transform.position;

        Vector3 moveVector = new Vector3(dir.x * cameraSpeed *Time.deltaTime, dir.y * cameraSpeed * Time.deltaTime, 0.0f);
        this.transform.Translate(moveVector);
    }
}
