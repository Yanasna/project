using UnityEngine;
using UnityEngine.SceneManagement;

public class FirstButtonClick : MonoBehaviour
{   
    public String sceneName;
    public void OnClickButton(){
        SceneManager.LoadScene("sceneName);
    }
    // Start is called once before the first execution of Update after the MonoBehaviour is created

    // Update is called once per frame
}
