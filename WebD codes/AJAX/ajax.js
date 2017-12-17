function ajaxRequest(filename, callback, responseType = "", mimeType = null) {
    if (filename == "") return null;
    var request;
    try {
        // Opera 8.0+, Firefox, Safari,Chrome,IE7+
        request = new XMLHttpRequest();
    }
    catch (e) {
        // Internet Explorer Browsers
        try {
            request = new ActiveXObject("Msxml2.XMLHTTP");
        }
        catch (e) {
            try {
                request = new ActiveXObject("Microsoft.XMLHTTP");
            }
            catch (e) {
                throw new Error("Some Error Occurred! Not able to make ajax request.");
            }
        }
    }

    request.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            //TO DO code goes here...
            callback(this.response);
        }
        //else
        //    throw new Error("Error: " + this.statusText);
    }

    if (mimeType != null)
        request.overrideMimeType(mimeType);
    request.responseType = responseType;
    request.open("GET", filename, true);
    request.send(null);
}
