using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Http : MonoBehaviour
{
    private HTTP_Handler connexion;
    public string apikey;

    void Start()
    {
        connexion = new HTTP_Handler();

        connexion.httpRequest(this, "localhost/api/connect.php?apikey=" + apikey, result);
    }

    void result(object result)
    {
        Debug.Log(result);
        if (result != null)
        {
            connexion.httpRequest(this, "localhost/api/leaderboard.php?token=" + result.ToString().Trim(), ReadLeaderboard);
        }
    }

    void ReadLeaderboard(object result)
    {
        Debug.Log(result);
    }
}
