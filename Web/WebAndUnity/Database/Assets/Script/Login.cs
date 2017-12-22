using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using System.Text.RegularExpressions;
using UnityEngine.SceneManagement;

public class Login : MonoBehaviour
{
    private HTTP_Handler connexion;
    public string apikey;

    public InputField username_input;
    public InputField password_input;
    public InputField score_input;
    public Text leaderboard_name;
    public Text leaderboard_score;

    public GameObject login_screen;
    public GameObject leaderboard_screen;
    public GameObject game_screen;

    private string token;

    private string password;
    private string username;
    private string[] leaderboard;

    void Start()
    {
        connexion = new HTTP_Handler();

        connexion.httpRequest(this, "localhost/api/connect.php?apikey=" + apikey, token_result);
    }

    void token_result(object result)
    {
        if (result != null)
        {
            token = result.ToString().Trim();
        }
        else
        {
            Debug.Log("Token not found");
        }
    }

    public void login()
    {
        username = username_input.text;
        password = password_input.text;
        connexion.httpRequest(this, "localhost/api/login.php?username=" + username + "&password=" + password + "&token=" + token, login_result);
    }

    void login_result(object result)
    {
        if(Regex.IsMatch(result.ToString().Trim(), "User exist"))
        {
            login_screen.SetActive(false);
            showgame();
        }
        else
        {
            Debug.Log(result.ToString());
        }
    }    

    public void showleaderboard()
    {
        game_screen.SetActive(false);
        leaderboard_screen.SetActive(true);
        connexion.httpRequest(this, "localhost/api/leaderboard.php?token=" + token, showleaderboard);
    }

    void showleaderboard(object result)
    {
        if (Regex.IsMatch(result.ToString().Trim(), "Token expired"))
        {
            leaderboard_screen.SetActive(false);
            game_screen.SetActive(false);
            login_screen.SetActive(true);
        }

        leaderboard_name.text = "";
        leaderboard_score.text = "";
        leaderboard = result.ToString().Trim().Split('-');
        for (int i = 0; i < 10; i++)
        {
            if (i >= leaderboard.Length || leaderboard[i] == "")
            {
                break;
            }
            string[] UserPos = leaderboard[i].Split(' ');
            leaderboard_name.text += (1+i).ToString() + ". " + UserPos[0] + "\n";
            leaderboard_score.text += UserPos[1] + "\n";
        }
    }

    public void showgame()
    {
        leaderboard_screen.SetActive(false);
        game_screen.SetActive(true);
    }

    public void UpdateScore()
    {
        leaderboard_screen.SetActive(true);
        game_screen.SetActive(false);
        connexion.httpRequest(this, "localhost/api/newscore.php?username=" + username + "&score=" + score_input.text + "&token=" + token, go_to_leaderboard);
    }

    void go_to_leaderboard(object result)
    {
        showleaderboard();
    }
}
