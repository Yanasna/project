using UnityEngine;
using UnityEngine.SceneManagement;

public class FirstButtonClick : MonoBehaviour
{   
    public void OnClickButton(){
        SceneManager.LoadScene("Main");
    }
    // Start is called once before the first execution of Update after the MonoBehaviour is created

    // Update is called once per frame
}
