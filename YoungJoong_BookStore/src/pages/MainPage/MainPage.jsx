import React from 'react';
import './mainpage.css'
import { BrowserRouter as Router,
    Routes,
    Route,
    Link 
} from "react-router-dom"

import Index from '../Index/Index';
import Genre from '../Genre/Genre';
import NewBook from '../NewBook/NewBook';
import BestSeller from '../BestSeller/BestSeller';
import About from '../About/About';

import Art from '../Genre/Art';
import History from '../Genre/History';
import Science from '../Genre/Science';
import Novel from '../Genre/Novel';
import Money from '../Genre/Money';
import Fehak from '../Genre/Fehak';

export default function MainPage(){
    return(
        <Router>
            <header className ="navbar">  
                <div><Link to = "/" className='logo'>영중 책방</Link></div>  {/*영중책방 글자 누르면 해당 위치로 이동*/}
                    <ul className='menu'>
                        <li><Link to="/Genre">장르</Link></li> {/*장르 글자를 누르면 장르페이지(Genre) 이동*/}
                        <li><Link to="/NewBook">신간도서</Link></li> {/*신간도서 글자를 누르면 신간 도서 페이지(NewBook) 이동*/}
                        <li><Link to="/BestSeller">인기도서</Link></li> {/*인기도서 글자를 누르면 인기 도서 페이지(BestSeller) 이동*/}
                        <li><Link to="/About">About</Link></li> {/*About 글자를 누르면 About페이지 이동*/}
                    </ul>
            </header>
                <main>
                    <Routes>{/*라우터 path 구성과 element 페이지로 연결*/}
                        <Route path='/' element={<Index />} />  {/*index페이지 연결*/}
                        <Route path='Genre' element={<Genre />} > {/*Genre페이지 연결*/}
                            <Route path='Art' element={<Art />} /> {/*Art페이지 연결*/}
                            <Route path='Fehak' element={<Fehak />} /> {/*Fehak페이지 연결*/}
                            <Route path='History' element={<History />} /> {/*History페이지 연결*/}
                            <Route path='Money' element={<Money />} /> {/*Money페이지 연결*/}
                            <Route path='Novel' element={<Novel />} /> {/*Novel페이지 연결*/}
                            <Route path='Science' element={<Science />} /> {/*Science페이지 연결*/}
                        </Route>
                        <Route path='/NewBook' element={<NewBook />} /> {/*NewBook페이지 연결*/}
                        <Route path='/BestSeller' element={<BestSeller />} /> {/*BestSeller페이지 연결*/}
                        <Route path='/About' element={<About />} /> {/*About페이지 연결*/}
                    </Routes>
                </main>
            <footer className="footer">
                <div className="footer-info">
                    <p>동양미래대학교 컴퓨터소프트웨어학과</p>
                    <p>20221053 김영중</p>
                </div>
                <div className='footer-sub'>
                    <p>웹프런트앤드 프로젝트</p>
                </div>{/*화면 밑쪽에 눌렀을시 상단 위로 페이지를 자연스럽게 올리는 버튼 구성, */}
                <button className="scroll-top-btn" onClick={() => window.scrollTo({ top: 0, behavior: 'smooth' })}>↑</button>
            </footer>
        </Router>  
            )   
}