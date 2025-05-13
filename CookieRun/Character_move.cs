using System.Collections;
using Unity.VisualScripting;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.SocialPlatforms.Impl;
using UnityEngine.UI;


public class Character_move : MonoBehaviour
{
    public float moveSpeed = 5.0f;
    public float jumpforce = 8f; //점프힘
    private Rigidbody2D rb;

    private BoxCollider2D bc;

    private int jumpcount = 0;

    public static int EndScore = 0;
    public int Heart = 150;

    public int Score = 0;

    private float jumpBufferTime = 0.1f;

    private float jumpBufferCount;
    public Animator animator;
    //애니메이터 컴포넌트 가져오기

    bool isSliding = false; //슬라이딩 애니메이션 만들기 위해 선언


    public Vector2 slideOffset = new Vector2(0.5f, -0.1f);
    void Start()
    {
        InvokeRepeating("DrainHeart", 1f, 1f);
        rb = GetComponent<Rigidbody2D>();
        animator = GetComponent<Animator>();
        bc = GetComponent<BoxCollider2D>();
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
        animator.ResetTrigger("isJumping");
        animator.ResetTrigger("isDoubleJumping");
       }
               
        if(collision.gameObject.CompareTag("Obstacle"))
       {
        Heart -= 30;
        Destroy(collision.gameObject);
       }
       if(collision.gameObject.CompareTag("Item"))
       {
        Score += 1000;
        Destroy(collision.gameObject);
       }
       if(collision.gameObject.CompareTag("Death"))
       {
            SceneManager.LoadScene("EndGame");
       }
    }
    void Update()
    {   
        transform.Translate(Vector2.right * moveSpeed * Time.deltaTime);
        if(Heart <= 0){
            EndScore = Score;
            SceneManager.LoadScene("EndGame");
        } //앞으로 5f만큼 계속 전진
        if(HpSlider != null){
            HpSlider.value = Heart;
        }//Hp바를 계속 업데이트 
       
       animator.SetBool("isRunning", true);

       if(Input.GetKeyDown(KeyCode.DownArrow) && jumpcount == 0 && !isSliding){
            animator.SetBool("isSliding", true);
            isSliding = true;
       }
       if(Input.GetKeyUp(KeyCode.DownArrow) && isSliding){
            animator.SetBool("isSliding", false);
            isSliding = false;
       }
        if(Input.GetKeyDown(KeyCode.Space) && jumpcount < 2)
        {   
            rb.linearVelocity =  new Vector2(rb.linearVelocity.x, 0);
            rb.AddForce(Vector2.up *jumpforce, ForceMode2D.Impulse);

            if(jumpcount == 0){
                animator.SetTrigger("isJumping");
            }
            else if(jumpcount == 1)
            {
                animator.SetTrigger("isDoubleJumping");
            }
            jumpcount++;
        }//점프구현

    }
    public float maxHp = 150f;

    public Slider HpSlider; //Hp바를 참조받음

}
