var themeValue = window.localStorage.getItem('theme');
if (themeValue != undefined) {
    if (themeValue == 1) {
        changeTheme(themeValue, 'fas fa-moon');
    } else {
        changeTheme(themeValue, 'fas fa-sun');
    }
}


var themeBtn = document.getElementById('changeThemeBtn');
themeBtn.addEventListener('click', function() {
    if (window.localStorage.getItem('theme') == 1) {
        changeTheme(2, 'fas fa-sun');

    } else {
        changeTheme(1, 'fas fa-moon');
    } 
});


function changeTheme(theme, iconClass) {
    var stylesheet = document.getElementById('themeCSSLink');
    stylesheet.setAttribute('href', './assets/css/theme'+theme+'.css');
    window.localStorage.setItem('theme', theme);

    document.getElementById('changeThemeIcon').className = iconClass;
    document.getElementById('favicon').setAttribute('href', './assets/images/favicon'+theme+'.ico')

        
} // function changeTheme(theme)








