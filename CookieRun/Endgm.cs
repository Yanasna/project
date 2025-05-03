using System.Runtime.InteropServices;
using TMPro;
using UnityEngine;

public class Endgm : MonoBehaviour
{

    public TextMeshProUGUI tm;
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        tm.text = "Score : " + Character_move.EndScore; 
    }
}
