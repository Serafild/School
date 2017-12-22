using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using System.Text.RegularExpressions;

public class HTTP_Handler
{
    private const float timeout = 10;

    public void httpRequest(MonoBehaviour owner, string url, Action<object> callback)
    {
        owner.StartCoroutine(Communicate(owner, url, callback));
    }

    public IEnumerator Communicate(MonoBehaviour owner, string url, Action<object> callback)
    {
        Corout connexion = new Corout(owner, www(url));
        yield return connexion.coroutine;

        bool error404 = Regex.IsMatch(connexion.result.ToString(), "Error 404");

        if (error404)
        {
            callback("Failed to load resource: the server responded with a status of 404 (Not Found)");
        }
        else if (!(connexion.result is string))
        {
            callback("Connexion failed...");
        }
        else
        {
            callback(connexion.result);
        }
    }

    private IEnumerator www(string url)
    {
        WWW www = new WWW(url);
        float timeStamp = Time.time;
        string result = null;

        while (!www.isDone)
        {
            // Handle error
            if (timeStamp + timeout <= Time.time)
            {
                result = "Fatal Error: HttpRequest timeout";
                break;
            }
        }
        yield return result ?? www.text;
    }
}
