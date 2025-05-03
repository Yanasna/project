using TMPro;
using UnityEngine;
using UnityEngine.SocialPlatforms.Impl;
using UnityEngine.UI;

public class PlayerScore : MonoBehaviour
{
    public TextMeshProUGUI scoreText;
    public TextMeshProUGUI Hp;
    public Character_move cm;
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        scoreText.text = "Score : " + cm.Score; 
        Hp.text = "Hp : " + cm.Heart;
        transform.position = Camera.main.transform.position + new Vector3(-120f, 80f, 10f);
    }
}
