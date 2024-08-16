db.listingsAndReviews.find(

 { host_picture_url: { $exists: true, $ne: null } },

 { listing_url: 1, name: 1, address: 1, host_picture_url: 1 }

)

db.E-commerce.aggregate([

 {

 $group: {

 _id: null,

 totalReviews: { $sum: 1 },

 averageRating: { $avg: "$rating" },

 highestRating: { $max: "$rating" },

 lowestRating: { $min: "$rating" }

 }

 },

 {

 $project: {

 _id: 0,

 totalReviews: 1,

 averageRating: 1,

 highestRating: 1,

 lowestRating: 1

 }

 }

])
