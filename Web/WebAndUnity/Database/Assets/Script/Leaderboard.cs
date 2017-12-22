using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Leaderboard : MonoBehaviour {

    private HTTP_Handler connexion;

    string[] Score;

    void Start()
    {
        connexion = new HTTP_Handler();

        connexion.httpRequest(this, "localhost/api/leaderboard.php", ShowLeaderboard);
    }

    void ShowLeaderboard(object result)
    {
        Debug.Log(result.ToString().Trim());
        Score = result.ToString().Trim().Split(' ');
        for (int i = 0; i < Score.Length; i++)
        {
            Debug.Log(Score[i]);
        }        
    }
}
