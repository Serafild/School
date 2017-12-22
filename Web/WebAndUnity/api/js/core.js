(function() {
    var script = document.createElement("SCRIPT");
    script.src = 'https://ajax.googleapis.com/ajax/libs/jquery/1.7.1/jquery.min.js';
    script.type = 'text/javascript';
    document.getElementsByTagName("head")[0].appendChild(script);

    // Poll for jQuery to come into existance
    var checkReady = function(callback) {
        if (window.jQuery) {
            callback(jQuery);
        }
        else {
            window.setTimeout(function() { checkReady(callback); }, 100);
        }
    };
})
();

function processErrors(){
    var password = jQuery('#password').val();
    var passwordconfirmation = jQuery('#passwordconfirmation').val();

    if(password == passwordconfirmation){
        jQuery('span.handler').text('Password match!');
    }
    else{
        jQuery('span.handler').text('Password doesnt match!');
    }
}