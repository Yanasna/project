import { MoneyData } from "../../database/MoneyData";

{/*경제 페이지*/}
export default function Money(){
    return(
        <div>
<p className="title">경제</p>
            {MoneyData.map(item=>(<div key={item.id}>
                <div className="book-layout">
                    <img src = {item.bookImg} alt = {item.bookName} className="book-img"/>{/*책의 이미지를 가져온다.*/}
                    <div className="book-info">
                        <p className="book-title">- {item.bookName}</p>{/*책 이름 가져온다.*/}
                        <br />
                        <br />
                        <p>{item.writer}</p>{/*작가, 출판사 정보를 가져온다.*/}
                        <br />
                        <br />
                        <p className="book-price">가격 : {item.price}</p>{/*책의 가격 정보를 가져온다.*/}
                        <br />
                        <br />
                        <div  className="book-explain">
                            <p>{item.explain}</p>{/*책의 줄거리를 가져온다.*/}
                        </div>    
                    </div>               
                </div>
            </div>))}                
        </div>
    );
}