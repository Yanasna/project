import React from "react";
import { NewBookData } from "../../database/NewBookData";
import './newBook.css'

export default function NewBook(){
    return(
        <div>
            <p className="title">신간도서</p>
            {NewBookData.map(item=>(<div key={item.id}>
                <div className="book-layout">
                    <img src = {item.bookImg} alt = {item.bookName} className="book-img"/>
                    <div className="book-info">
                        <p className="book-title">- {item.bookName}</p>
                        <br />
                        <br />
                        <p>{item.writer}</p>
                        <br />
                        <p className="book-price">{item.export}</p>
                        <br />
                        <p className="book-price">가격 : {item.price}</p>
                        <br />
                        <br />
                        <div  className="book-explain">
                            <p>{item.explain}</p>
                        </div>    
                    </div>               
                </div>
            </div>))}
        </div>
    );

}