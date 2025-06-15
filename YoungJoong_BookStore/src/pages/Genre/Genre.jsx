// ./src/pages/HomePage/HomePage.jsx

import './genre.css'
import { BookGenre } from '../../database/BookGenre';
import { Outlet } from 'react-router-dom';
import { Link } from "react-router-dom"

{/*Genre 내용*/}
function Genre() {
    return (
            <div>
                <Outlet />{/*Outlet으로 MainPage.jsx에 Genre자식라우터들을 가져온다. */}
                <h1 className='title'>장르를 선택하세요!</h1>
                <br />
                    <ul className='product-list'>
                        {BookGenre.map(item=><div key={item.id}> {/*BookGenre 파일에 있는 내용 map함수로 가져옴*/}
                            <div onClick={() => window.scrollTo({ top: 0})}>{/*장르에 해당하는 이미지나 글자 클릭했을 시 페이지가 맨 위로 올라오게 */} 
                                <p className='p-font'><Link to={item.Link}>{item.genre}</Link></p> {/*BookGenre에 있는 Link와 genre을 가져온다*/}
                                <Link to={item.Link}><img src={item.bookImg} alt="img" /></Link>   {/*BookGenre에 있는 Link와 이미지를 가져온다.*/}
                            </div>
                        </div>
                        )}
                    </ul>
                    
            </div>
    );
}            
export default Genre;
