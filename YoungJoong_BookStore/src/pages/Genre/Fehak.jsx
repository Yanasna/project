import { FehakData } from "../../database/FehakData";

export default function Fehak(){
    return(
        <div>
<p className="title">철학</p>
            {FehakData.map(item=>(<div key={item.id}>{/*FehakData 파일에 있는 내용 map함수로 가져옴*/}
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