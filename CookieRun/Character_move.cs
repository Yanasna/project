using System.Collections;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.SocialPlatforms.Impl;


public class Character_move : MonoBehaviour
{
    public float moveSpeed = 5.0f;
    public float jumpforce = 8f; //점프힘
    private Rigidbody2D rb;
    private int jumpcount = 0;

    public static int EndScore = 0;
    public int Heart = 150;

    public int Score = 0;

    public string[] Candy = new string[]{"Candy_0", "Candy_1", "Candy_2", "Candy_3", "Candy_4", "Candy_5"};
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    public string[] Obstacle = new string[]{"Obstacle_0", "Obstacle_1"};

    void Start()
    {
        InvokeRepeating("DrainHeart", 1f, 1f);
        rb = GetComponent<Rigidbody2D>();
    }
    
    void DrainHeart(){
        if(Heart > 0){
        Heart--;
        }
    }
    private void OnCollisionEnter2D(Collision2D collision)
    {
       if(collision.gameObject.CompareTag("Ground"))
       {
        jumpcount = 0;
       }
        if(collision.gameObject.CompareTag("Obstacle"))
       {
        Heart -= 30;
        for(int i = 0; i < Obstacle.Length; i++){
        if(collision.gameObject.name == Obstacle[i]){
                Destroy(collision.gameObject);
            }
        }
       }
       if(collision.gameObject.CompareTag("Item"))
       {
        Score += 1000;
        for(int i = 0; i<Candy.Length; i++){
            if(collision.gameObject.name == Candy[i]){
                Destroy(collision.gameObject);
            }
        }
       }
       if(collision.gameObject.CompareTag("Death"))
       {
            EndScore = Score;
            SceneManager.LoadScene("EndGame");
       }
    }
    void Update()
    {
        transform.Translate(Vector2.right * moveSpeed * Time.deltaTime);
        if(Heart <= 0){
            EndScore = Score;
            SceneManager.LoadScene("EndGame");
        }
        //앞으로 5f만큼 계속 전진
    }
    public void FixedUpdate()
    {
        if(Input.GetKeyDown(KeyCode.Space) && jumpcount < 2)
        {   
            rb.linearVelocity =  new Vector2(rb.linearVelocity.x, 0);
            rb.AddForce(Vector2.up *jumpforce, ForceMode2D.Impulse);
            jumpcount++;
        }//점프구현
    }
}
