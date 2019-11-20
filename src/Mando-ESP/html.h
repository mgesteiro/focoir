// https://stackoverflow.com/questions/4389932/how-do-you-disable-viewport-zooming-on-mobile-safari
R"(
<!DOCTYPE html>
<html lang='es'>
<head>
  <meta http-equiv='Content-Type' content='text/html; charset=utf-8'>
  <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no">
  <title>Mando a distancia FocoRGB</title>
  <style>
    body {margin:0;padding:0;text-align:center;font-family:sans-serif;}
    .box {margin:0 auto;padding:0;line-height:0;}
    @media screen and (orientation:landscape){.box{height:100vh;width:60vh;}body{font-size:3.6vmin;}}
    @media screen and (orientation:portrait){.box{height:165vw;width:100vw;}body{font-size:6vmin;}}
    .circle {border-radius:50%;border:1px black solid;display:inline-block;margin:1%;width:22%;height:13.2%;background-color:gray;cursor:pointer;}
    #a, #b, #h { background:white;}
    #c { background:black;}
    #d, #e { background:red;}
    #f { background:green;}
    #g { background:blue;}
    #i { background-color:#f08a5d;}
    #j { background-color:#51a573;}
    #k { background-color:#2465cd;}
    #m { background-color:#ec975a;}
    #n { background-color:#3d9bb9;}
    #o { background-color:#5a3568;}
    #q { background-color:#e5a948;}
    #r { background-color:#0772a7;}
    #s { background-color:#7b3e7d;}
    #u { background-color:#efe33b;}
    #v { background-color:#0f5da5;}
    #w { background-color:#c24a91;}
    h1 {
      font-size: 110%;
    }
    .circle p {
      float: left;
      margin: 50% auto;
      width: 100%;
    }
    noscript{color:red;}
    noscript h1{font-size:10vmin;}
    noscript h2{font-size:5vmin;}
    noscript hr{margin:10%;border:2px solid red;}
  </style>
  <script type='text/javascript' >
    var xhr = new XMLHttpRequest();
    function enviar(control) {
      xhr.open('GET', 'accion?comando=' + control.id);
      xhr.send();
    }
  </script>
</head>
<body>
  <noscript>
    <h1>JavaScript DESACTIVADO</h1>
    <h2>este mando lo necesita para funcionar :(</h2>
    <hr />
  </noscript>
  <div class='box'>
    <h1>Mando para foco RGB</h1>
    <div class='circle' id='a' onclick='enviar(this);' ><p>+</p></div><div class='circle' id='b' onclick='enviar(this);' ><p>-</p></div><div class='circle' id='c' onclick='enviar(this);' ><p style="color: white;">off</p></div><div class='circle' id='d' onclick='enviar(this);' ><p>on</p></div>
    <br/>
    <div class='circle' id='e' onclick='enviar(this);' ><p>R</p></div><div class='circle' id='f' onclick='enviar(this);' ><p>G</p></div><div class='circle' id='g' onclick='enviar(this);' ><p>B</p></div><div class='circle' id='h' onclick='enviar(this);' ><p>W</p></div>
    <br/>
    <div class='circle' id='i' onclick='enviar(this);' ></div><div class='circle' id='j' onclick='enviar(this);' ></div><div class='circle' id='k' onclick='enviar(this);' ></div><div class='circle' id='l' onclick='enviar(this);' ><p>flash</p></div>
    <br/>
    <div class='circle' id='m' onclick='enviar(this);' ></div><div class='circle' id='n' onclick='enviar(this);' ></div><div class='circle' id='o' onclick='enviar(this);' ></div><div class='circle' id='p' onclick='enviar(this);' ><p>strobe</p></div>
    <br/>
    <div class='circle' id='q' onclick='enviar(this);' ></div><div class='circle' id='r' onclick='enviar(this);' ></div><div class='circle' id='s' onclick='enviar(this);' ></div><div class='circle' id='t' onclick='enviar(this);' ><p>fade</p></div>
    <br/>
    <div class='circle' id='u' onclick='enviar(this);' ></div><div class='circle' id='v' onclick='enviar(this);' ></div><div class='circle' id='w' onclick='enviar(this);' ></div><div class='circle' id='x' onclick='enviar(this);' ><p>smooth</p></div>
  </div>
</body>
</html>
)";
