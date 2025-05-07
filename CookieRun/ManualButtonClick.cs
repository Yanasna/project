using UnityEngine;
using UnityEngine.SceneManagement;

public class ManualButtonClick : MonoBehaviour
{   
    public void OnClickButton(){
        SceneManager.LoadScene("Main");
    }
    // Start is called once before the first execution of Update after the MonoBehaviour is created

    // Update is called once per frame
}
