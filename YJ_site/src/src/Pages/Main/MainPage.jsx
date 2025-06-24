import React from 'react'
import { BrowserRouter as Router,
    Routes,
    Route,
    Link 
} from "react-router-dom"
import './MainPage.css'

import Index from '../Index/Index';
import Taza from '../Taza/Taza';
import Game from '../Game/Game';
import UpdateNote from '../UpdateNote/UpdateNote';

import CookieRun from '../Game/Games/CookieRun';

export default function MainPage() {
  return (
    <Router>
           <header className ="navbar">  
                <div><Link to = "/" className='logo'>YJ-GAME</Link></div>  {/*YJ_GAME 글자 누르면 해당 위치로 이동*/}
                    <ul className='menu'>
                        <li><Link to="/Taza">타자연습</Link></li> {/*타자연습을 누르면 타자연습 페이지로 이동*/}
                        <li><Link to="/Games">Games</Link></li> {/*신간도서 글자를 누르면 신간 도서 페이지(NewBook) 이동*/}
                        <li><Link to="/Update">Update기록</Link></li> {/*신간도서 글자를 누르면 신간 도서 페이지(NewBook) 이동*/}
                    </ul>
            </header>
                <main>
                    <Routes>{/*라우터 path 구성과 element 페이지로 연결*/}
                        <Route path='/' element={<Index />} />  {/*index페이지 연결*/}
                       
                        <Route path='/Taza' element={<Taza />} /> {/*타자연습 페이지 연결*/}

                        <Route path='Games' element={<Game />} > {/*게임 페이지 연결*/}
                            <Route path='CookieRun' element ={<CookieRun />}/>
                        </Route>

                        <Route path='/Update' element={<UpdateNote />} /> {/*타자연습 페이지 연결*/}
                    </Routes>
                </main>
            <footer className="footer">
                <div className="footer-info">
                    <p>Made in 김영중</p>
                </div>
                <div className='footer-sub'>
                    <p>YJ</p>
                </div>{/*화면 밑쪽에 눌렀을시 상단 위로 페이지를 자연스럽게 올리는 버튼 구성, */}
                <button className="scroll-top-btn" onClick={() => window.scrollTo({ top: 0, behavior: 'smooth' })}>↑</button>
            </footer> 
    </Router>  
  )
}
