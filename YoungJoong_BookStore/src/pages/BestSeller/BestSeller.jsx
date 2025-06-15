import React from "react";
import { BestSellerData } from "../../database/BestSellerData";
import './BestSeller.css'

{/*인기 도서 페이지*/}
export default function BestSeller(){
    return(
        <div>
            <p className="title">인기도서</p> 
            {BestSellerData.map(item=>(<div key={item.id}> {/*BestSellerData 파일에 있는 내용 map함수로 가져온다.*/}
                <div className="book-layout">
                    <img src = {item.bookImg} alt = {item.bookName} className="book-img"/>{/*책의 이미지 가져온다.*/}
                    <div className="book-info">
                        <p className="book-title">- {item.bookName}</p>{/*책이 이름을 가져온다.*/}
                        <br />
                        <br />
                        <p>{item.writer}</p>{/*책의 작가와 출판사 정보를 가져온다.*/}
                        <br />
                        <br />
                        <p className="book-price">가격 : {item.price}</p>{/*책의 가격 정보를 가져온다.*/}
                        <br />
                        <br />
                        <div  className="book-explain">{/*책의 줄거리를 가져온다.*/}
                            <p>{item.explain}</p>
                        </div>    
                    </div>               
                </div>
            </div>))}
        </div>
    );

}