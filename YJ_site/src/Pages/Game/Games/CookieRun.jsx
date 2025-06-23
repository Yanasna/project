import { useEffect } from 'react'

export default function CookieRun() {
  useEffect(() => {
    const script = document.createElement("script")
    script.src = "/cookieRun/v.3.0_CookieRun_KYJ.loader.js"
    script.onload = () => {
      window.createUnityInstance(document.querySelector("#unity-canvas"), {
        dataUrl: "/cookieRun/v.3.0_CookieRun_KYJ.data",
        frameworkUrl: "/cookieRun/v.3.0_CookieRun_KYJ.framework.js",
        codeUrl: "/cookieRun/v.3.0_CookieRun_KYJ.wasm",
      }).then((unityInstance) => {
        console.log("Unity 게임 시작됨!")
      }).catch((err) => {
        console.error("Unity 로딩 실패", err)
      })
    }
    document.body.appendChild(script)
  }, [])

  return (
    <div style={{ textAlign: "center" }}>
        <div id="unity-container" style={{ width: "1200px", height: "600px" }}>
            <canvas id="unity-canvas" style={{ width: "100%", height: "100%" }}></canvas>
        </div>
        <p>쿠키런 모작</p>
        <li>json-사용하여 맵에 있는 오브젝트 구현(사탕, 장애물)</li>
    </div>
  )
}