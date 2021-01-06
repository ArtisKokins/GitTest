/*select author_name, author_surname, title
from book_list, author, book
where book_list.id_author=author.id_author
and book_list.id_book=book.id_book
and author.id_author = 3*/

/*# Pēc autora
select title as 'Book Title', genre_name as 'Genre', age_group_name as 'Age Group', publishing_date as 'Published'
from book_list, author, book, genre, age_group
where book_list.id_author=author.id_author
and book_list.id_book=book.id_book
and book.id_genre=genre.id_genre
and age_group.id_age_group=book.id_age_group
and author_name='Anthony'
and author_surname='Ryan'*/

/*# Pēc žanra
select title as 'Book Title', age_group_name as 'Age Group', genre_name as 'Genre'
from book_list, author, book, genre, age_group
where book.id_genre=genre.id_genre
and book_list.id_author=author.id_author
and book_list.id_book=book.id_book
and age_group.id_age_group=book.id_age_group
and genre_name = 'Sci-Fi'
group by title*/

/*# Izņemtās grāmatas
select title as 'Book Title', genre_name as 'Genre', age_group_name as 'Age Group', given_back as 'Given Back?'
from book, genre, age_group
where book.id_genre=genre.id_genre
and age_group.id_age_group=book.id_age_group
and given_back = 0
group by title*/

-- Jāpadomā kaut ko citu
/*# Pieejamās grāmatas
select title as 'Book Title', genre_name as 'Genre', age_group_name as 'Age Group'
from book, genre, age_group
where book.id_genre=genre.id_genre
and age_group.id_age_group=book.id_age_group
and given_back = 1
group by title*/

/*# Par konkrēta lasītāja karti
select title as 'Book Title', genre_name as 'Genre',
reader_card.taken_out as 'Taken Out', reader_card.given_back as 'Given Back', book.given_back as 'Given Back?'
from book, reader, reader_card, genre
where book.id_genre=genre.id_genre
and reader.id_reader=reader_card.id_reader
and reader_card.id_book=book.id_book
and reader.personal_code = '080880-29985'*/

/*# Par konkrēta lasītāja neizņemtajām grāmatām
select title as 'Book Title', genre_name as 'Genre',
reader_card.taken_out as 'Taken Out', reader_card.given_back as 'Given Back', book.given_back as 'Given Back?'
from book, reader, reader_card, genre
where book.id_genre=genre.id_genre
and reader.id_reader=reader_card.id_reader
and reader_card.id_book=book.id_book
and reader.personal_code = '300384-22222'
and book.given_back = 0*/

/*# Kad konkrētā grāmata tika izņemta un atdota
select reader_card.taken_out as 'Taken Out', reader_card.given_back as 'Given Back', reader.name as 'Name', reader.surname as 'Surname'
from book, reader, reader_card
where reader.id_reader=reader_card.id_reader
and reader_card.id_book=book.id_book
and book.title = 'The Empire of Ashes'*/

/*# Grāmatas, kuras izdotas no 2015 līdz 2018 gadam (2018 neieskaitot) un sakārtotas no jaunākās uz vecāko
select title as 'Book Title', publishing_date as 'Publishing Date'
from book
where date(publishing_date) between date('2015-01-01') and date('2018-01-01')
order by publishing_date desc*/

/*# Pēc lasītāja pieprasījuma nr.1
select title as 'Book Title', author_name as 'Name', author_surname as 'Surname'
from book, author, book_list, genre
where book.id_genre=genre.id_genre
and book_list.id_author=author.id_author
and book_list.id_book=book.id_book
and title like '%star%'
and genre_name = 'Romance'*/

/*# Pēc lasītāja pieprasījuma nr.2
select title as 'Book Title', author_name as 'Name', author_surname as 'Surname', publishing_date as 'Publishing Date'
from book, author, book_list, genre
where book.id_genre=genre.id_genre
and book_list.id_author=author.id_author
and book_list.id_book=book.id_book
and genre_name = 'Fantasy'
and date(publishing_date) between date('2010-01-01') and date('2020-01-01')
and book.given_back = 0
order by publishing_date*/
