(defn find-group [[r-o c-o] r-q c-q]
  (cond
    (and (= r-o r-q) (< c-o c-q)) :left
    (and (= r-o r-q) (> c-o c-q)) :right
    (and (= c-o c-q) (< r-o r-q)) :up
    (and (= c-o c-q) (> r-o r-q)) :down
    (and (= (- r-o r-q) (- c-o c-q)) (< c-q c-o) (< r-q r-o) ) :down-right
    (and (= (- r-o r-q) (- c-o c-q)) (< c-o c-q) (< r-o r-q) ) :up-left
    (and (= (- r-q r-o) (- c-o c-q)) (< r-q r-o) (< c-o c-q)) :down-left
    (and (= (- r-q r-o) (- c-o c-q)) (< r-o r-q) (< c-q c-o)) :up-right
    :else :nothing))

(defn min-abs [x y]
  (min (max x (- x)) (max y (- y))))

(defn find-len [[r-o c-o] r-q c-q type]
  (dec (case type
         :left (- c-q c-o)
         :right (- c-o c-q)
         :up (- r-q r-o)
         :down (- r-o r-q)
         (min-abs (- r-q r-o) (- c-o c-q)))))


(defn find-min [obstacles [r-q c-q] type]
  (apply min (map #(find-len % r-q c-q type ) obstacles)))

(defn choice-valid-obs [obstacles n r-q c-q]
  (->>
    (dissoc
      (->> obstacles
           (group-by #(find-group % r-q c-q))) :nothing)
   (map (fn [[type obstacle]] (find-min obstacle [r-q c-q] type))) 
    (reduce +)))

(defn border [n r_q c_q]
  (let [r-q (dec r_q)
        c-q (dec c_q)
        diff-r (- n r_q)
        diff-c (- n c_q)
        m1 (inc (min r-q diff-c))
        m2 (inc (min diff-r c-q))
        m3 (inc (min diff-r diff-c))
        m4 (inc (min r-q c-q))]
    [[0 c_q]
     [r_q 0]
     [r_q (inc n)]
     [(inc n) c_q]
     [(- r_q m4) (- c_q m4)]
     [(- r_q m1) (+ c_q m1)]
     [(+ r_q m2) (- c_q m2)]
     [(+ r_q m3) (+ c_q m3)]]))

(defn queensAttack [n k r_q c_q obstacles]
  (let [new-obs (concat (border n r_q c_q) obstacles)
        a (choice-valid-obs new-obs n r_q c_q)]
    a))
