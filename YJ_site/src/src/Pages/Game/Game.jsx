import React from 'react'
import { Link, Outlet } from 'react-router-dom'
import './Game.css'; 

export default function Game() {
  return (
    <div>
        <Outlet />
        <h1>게임을 선택하세요!</h1>
        <p>주의! 게임을 시작하는데에 시간이 많이 소요될 수 있습니다!!</p>
        <Link to='/Games/CookieRun'>
            <p>쿠키런 모작</p>
            <img src='../../gameImg/CookieRun.jpg' className='img-cover'/>
        </Link>
    </div>
  )
}
